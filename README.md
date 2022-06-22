# SPV node

Implementation of an SPV (Simplified Payment Verification) node on the blockchain in C++. It can be connected to the real
network like Bitcoin network. This implementation should be considered as a library that can be used to create running
lightweight node in some app that interacts with a real blockchain.

### The project needs to be a little upgraded. Here are the upgrades that will be done in the near future:
- [ ] generate hashes using libbitcoin library (not done yet)
- [ ] generate signatures using libbitcoin library (not done yet)
- [ ] check for the security of a node (not done yet)
- [ ] add tests that check for potential insecurity (not done yet)

### In the main.cpp file there is an example implementation and usage of this project. Steps that are done there:
1) Create 2 mock wallets, one that has 100 tokens and second one that has 0 tokens.
2) Generate random blockchain (normally we would be connected to some network and random blockchain generation would not
   be necessary)
3) Create a full node based on generated blockchain so that out spv node can verify transaction (normally we would find
   someone that is running ful blockchain)
4) Create some transactions (in this example we create one transaction that sends 30 tokens from wallet with amount 100
   to wallet with amount 0)
5) Create spv node (normally we would have app on our phone that is a lightweight node)
6) Running verify transaction on spv node returns number of tokens wallet from which the transaction were made

### What is actually SPV node and what it does?
Nowadays smartphones are really popular, but they do not have enough space to hold a full node (whole blockchain). Satoshi Nakamoto
in his Bitcoin whitepaper mentioned lightweight/ SPV node. It is especially useful for smartphones/ tablets and machines with low resources and storage.
For those devices a simplified payment verification system runs to allow them to operate without the full blockchain stored locally.
It is possible to verify bitcoin payments without running a full network node. SPV nodes download only the block headers and do not download the transactions
included in each block. The resulting chain of blocks, without transactions, is 1,000 times smaller than the full blockchain. To validate the information,
a user computes the Merkle root from the Merkle path of given transaction. The user then compares it with the Merkle root specified in the block header.
If they are the same, the user accepts that given transaction is in the chain.

### Additional library - libbitcoin and merkle_tree.h header.
This project has an additional librarys that users using it has to have installed:
- [libbitcoin](https://libbitcoin.info/)
- [merkle tree header file](https://github.com/microsoft/merklecpp) (it is included in src/merkle_tree directory, so you do not have to worry about it)

#### Run example main.cpp file
In order to run example main file with libbitcoin library:

g++ -o main main.cpp $(pkg-config --cflags --libs libbitcoin-system)