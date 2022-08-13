## KKToken client

### Description

KKToken client (KKTCLI) is the blockchain core with 
a default command line interface that provides 
access to effective operations in KKToken blockchain.

### Overview

    scr
    │
    ├── core                # service control
    │
    ├── crypto              # cryptography
    │
    ├── interface           # command line interface
    │   │
    │   ├── console         # CLI control
    │   │
    │   └── log             # CLI log
    │
    ├── serialization       # serialization
    │
    └── structs             # blockchain structures

## How To

### Setup project

#### Conan

This project uses **conan** as a package manager.

To install it you should have python 3 and pip installed ([more info](https://docs.conan.io/en/latest/installation.html)). Then just run

``` sh
pip install conan
```

#### Finish

Run this script to complete installation.

``` sh
tools/setup.sh
```

### Build project

Just run this to build project.

``` sh
tools/build.sh
```
