## Introduction
In this section, we will guide you through the creation of an application. This application will create a transaction that will be signed with the Ledger Nano before sending it to the blockchain.
The purpose of the application is to transfer VLX from your Velas account on your Ledger to another account.

### Install the Velas Nano App
First you need to install the Velas Nano App from Ledger Live.

### Start the Development Server
Start the development server:

```console
npm run start
```

Now the application is up and running. Open Chrome and go to [http://localhost:1234](http://localhost:1234), it will display :

{: .center}
[![Application running on browser](../images/tutorial-1-velas.png)](../assets/tutorial-1-velas.png){: style="border-bottom:none;"}   
*Fig. 3: Application Running on Browser*

### Plug Your Ledger Device
Before clicking on the text connect your Ledger to the USB port, unlock it and run the solana application.
The steps are described below.

{: .center}
[![Ledger Enter Code Pin](../images/ledgerCodePin.jpg){:width="480px"}](../images/ledgerCodePin.jpg){: style="border-bottom:none;"}   
*Fig. 4: Ledger Enter Code Pin*

{: .center}
[![Run Solana Application on Ledger Nano](../images/ledgerEth.jpg){:width="480px"}](../images/ledgerEth.jpg){: style="border-bottom:none;"}    
*Fig. 5: Run Solana Application on Ledger Nano*

{: .center}
[![Solana Application is Running on Ledger Nano](../images/ledgerReady.jpg){:width="480px"}](../images/ledgerReady.jpg){: style="border-bottom:none;"}    
*Fig. 6: Solana Application is Running on Ledger Nano*


### Connect Your Ledger to the Application
Now you can click on the "Connect your Wallet" button and a modal will be opened.
Click on the Ledger logo.

{: .center}
[![Choice of Wallet](../images/tutorial-1-solana-wallet.png)](../images/tutorial-1-solana-wallet.png){: style="border-bottom:none;"}   
*Fig. 7: Choice of Wallet*

Now choose the Ledger Nano to connect it to the browser.

{: .center}
[![Connect the Ledger Nano](../images/tutorial-1-solana-pairing.png)](../images/tutorial-1-solana-pairing.png){: style="border-bottom:none;"}   
*Fig. 8: Connect the Ledger Nano*

After connecting the Nano, click on "Get Information". If all goes well, the input fields will be filled with data. The greyed input is not to be changed and it is directly extracted either from the blockchain or from your Ledger Nano application.

{: .center}
[![Application After Connecting Ledger Nano](../images/tutorial-1-solana-info.png)](../images/tutorial-1-solana-info.png){: style="border-bottom:none;"}   
*Fig. 9: Application After Connecting Ledger Nano*

### Send Sol token to your Ledger Nano solana account
To send some sol tokens on the Devnet network, you can either go to one of the solana faucet websites or do it with the solana cli:
- [Solana Faucet](https://solfaucet.com/)
- [Solana CLI](https://docs.solana.com/cli/transfer-tokens)

If you are looking for the easier and quicker way, use the Solana Faucet. If you would rather use the Solana CLI, please read this documentation to [install it](https://docs.solana.com/cli) before starting sending Sol.

The Solana Devnet is not visible on Ledger Live, you can then check the transaction passed on [the Solana Explorer](https://explorer.solana.com/?cluster=devnet). 

#### Option n°1 - Solana Faucet
Go to the [Solana Faucet](https://solfaucet.com/) website put your Wallet Public Key (displayed on the web app) on the input and click on "Devnet"

{: .center}
[![Solana Faucet](../images/solana-faucet.png){:width="840"}](../images/solana-faucet.png){: style="border-bottom:none;"}   
*Fig. 1: Solana Faucet*

#### Option n°2 -Solana CLI
Go to the [Solana CLI](https://docs.solana.com/cli/transfer-tokens) website, there are the steps to add some sol to your account.

```console
solana airdrop 1 <RECIPIENT_ACCOUNT_ADDRESS> --url https://api.devnet.solana.com
```
For example
```console
solana airdrop 1 72tCcW6F4gRWJLCXf3RGejNDZBwUvWCfxHTdxoLGV4ht --url https://api.devnet.solana.com
```

### Create a transaction to transfer sol

Now that the inputs are filled with data. It is time to transfer some sol tokens from your Ledger solana account to another account (you can keep the default account on the "index.js" file).  
Therefore, click on "Create Transaction" to create the transaction which will be signed by your ledger before sending it to the blockchain.  

{: .center}
[![Application After Connecting Ledger Nano](../images/tutorial-1-solana-create.png)](../images/tutorial-1-solana-create.png){: style="border-bottom:none;"}   
*Fig. 10: Application After Connecting Ledger Nano*

When the transaction proceed and finalize, an URL will be displayed on the screen. This URL is a link to Solana Explorer to review the transaction.  
There you can find all the information concerning the transaction you have previously sent.

{: .center}
[![Result after Sending Transaction](../images/tutorial-1-solana-transaction.png)](../images/tutorial-1-solana-transaction.png){: style="border-bottom:none;"}   
*Fig. 11: Transaction Information URL*

If you go on Solana Explorer you can see the information of your transaction.

{: .center}
[![Result after Sending Transaction](../images/solana-explorer-1.png)](../images/solana-explorer-1.png){: style="border-bottom:none;"}   
*Fig. 12: Result on Solana Explorer after Sending Transaction*

{: .center}
[![Result after Sending Transaction](../images/solana-explorer-2.png)](../images/solana-explorer-2.png){: style="border-bottom:none;"}   
*Fig. 13: Result on Solana Explorer after Sending Transaction*


Congratulations, you have successfully built your first transfer application connected with Ledger !!!