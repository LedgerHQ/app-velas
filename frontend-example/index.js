import * as VelasWeb3 from '@solana/web3.js';
import TransportWebUSB from "@ledgerhq/hw-transport-webusb";
import Velas from "@ledgerhq/hw-app-solana";
import { listen } from "@ledgerhq/logs";
import bs58 from "bs58";

//Provider for Velas testnet network
const connection = new VelasWeb3.Connection("https://explorer.testnet.velas.com/rpc");

let transport;
let _velas;
let addressWallet;
let recipient = VelasWeb3.Keypair.generate().publicKey;
let value = 0.1;
let gasPrice;

listen(log => console.log(log));

document.getElementById("connect-ledger").onclick = async function () {
    //Connecting to the Ledger Nano with HID protocol
    transport = await TransportWebUSB.create();

    //Getting an Ethereum instance and get the Ledger Nano ethereum account public key
    _velas = new Velas(transport);
    const { address } = await _velas.getAddress("44'/501'");

    addressWallet = new VelasWeb3.PublicKey(bs58.encode(address));

    console.log(connection);
    const balance = await connection.getBalance(addressWallet);


    //Get some properties from provider
    gasPrice = VelasWeb3.LAMPORTS_PER_SOL / 100;

    //Fill the inputs with the default value
    document.getElementById("wallet").value = bs58.encode(address);
    document.getElementById("balance").value = balance/ VelasWeb3.LAMPORTS_PER_SOL;
    document.getElementById("gasPrice").value = parseInt(gasPrice) + " wei";
    document.getElementById("value").value = value;
    document.getElementById("recipient").value = recipient.toBase58();
}


document.getElementById("tx-transfer").onclick = async function () {
    //Getting information from the inputs
    recipient = new VelasWeb3.PublicKey(document.getElementById("recipient").value);
    value = document.getElementById("value").value;

    //Building transaction with the information gathered
    try {
        const recentBlockhash = await connection.getRecentBlockhash();
        const transaction = new VelasWeb3.Transaction({ feePayer: addressWallet, recentBlockhash: recentBlockhash.blockhash}).add(
            VelasWeb3.SystemProgram.transfer({
                fromPubkey: addressWallet,
                toPubkey: recipient,
                lamports: VelasWeb3.LAMPORTS_PER_SOL * value,
            }),
        );


        //Serializing the transaction to pass it to Ledger Nano for signing
        const unsignedTx = transaction.serializeMessage();

        //Sign with the Ledger Nano (Sign what you see)
        const { signature } = await _velas.signTransaction("44'/501'", unsignedTx);
        transaction.addSignature(addressWallet,signature);

        //Serialize the same transaction as before, but added the signature on it
        const signedTx = transaction.serialize();


        //Sending the transaction to the blockchain
        const hash = await connection.sendRawTransaction(signedTx, {preflightCommitment:"confirmed", skipPreflight: false});

        //Display the Ropsten etherscan on the screen
        const url = "https://native.velas.com/tx/" + hash + "?cluster=testnet";
        document.getElementById("url").innerHTML = url;
        document.getElementById("url").href = url;
    } catch (error) {
        console.log(error);
    }
}