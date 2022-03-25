[![Compilation & tests](https://github.com/blooo-io/LedgerHQ-app-velas/actions/workflows/ci-workflow.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-velas/actions/workflows/ci-workflow.yml)
[![Code style check](https://github.com/blooo-io/LedgerHQ-app-velas/actions/workflows/lint-workflow.yml/badge.svg)](https://github.com/blooo-io/LedgerHQ-app-velas/actions/workflows/lint-workflow.yml)

# Velas app for Ledger Wallet

## Overview

This app adds support for the Velas native token to Ledger Nano S hardware wallet.

Current Features:
- Pubkey queries
- Parse, display and sign all Velas CLI generated transaction formats
- Blind sign arbitrary transactions (Enabled via settings)

## Prerequisites

Clone this git repo recursively, such that it includes the BOLOS SDK in a submodule:

```bash
$ git clone git@github.com:blooo-io/LedgerHQ-app-velas.git
cd LedgerHQ-app-velas
```

## Creating the development environment

You can use an Ubuntu 20.04 VM or a dedicated OS

## Alternative Setup, For those not using Vagrant

To build and install the app on your Ledger Nano S you must set up the Ledger Nano S build environments. Please follow the Getting Started instructions at [here](https://ledger.readthedocs.io/en/latest/userspace/getting_started.html).


install prerequisite and switch to a Nano X dev-env:

```bash
sudo apt install libudev-dev libusb-1.0-0-dev docker.io
```

## Building and installing

In order to compile and unit test the app you have to use the docker ledger builder image

```bash

./start_builder.sh
# docker run --rm -ti -v "$(realpath .):/app" --privileged ghcr.io/ledgerhq/ledger-app-builder/ledger-app-builder:latest

```

`--privileged `: option allowing to deploy the app on the ledger nano S hardware wallet later.


### Nano S

Compile within the docker container:

```bash
make clean
make BOLOS_SDK=$NANOS_SDK
```
### Nano X

```bash
make clean
make BOLOS_SDK=$NANOX_SDK
```



Refresh the repo (required after Makefile edits):
```bash
make clean
```

Run C tests:
```bash
make -C libsol
```

Load the app onto the device:

```bash
make load
```

Remove the app from the device:

```bash
make delete
```


## Example of Ledger wallet functionality

To test the application using a the real Nano S hardware:

1. Connect the hardware wallet to the VM / Linux Machine.
2. Unlock the ledger Nano S and open the Velas App.
3. Go to `Settings` and select Yes for `Allow Blind Signing`.
4. Then from the project source directory:

```bash
cd tests
cargo run
```

## Documentation

This follows the specification available in the [`api.md`](doc/api.md).
