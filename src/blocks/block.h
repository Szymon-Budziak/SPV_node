#ifndef BLOCK_H
#define BLOCK_H

#include <list>
#include <iterator>
#include <iostream>
#include "block_header.cpp"
#include "../transaction/transaction.h"
#include "../merkle_tree/merkle_tree.h"

class Block {
private:
    static unsigned int block_counter;
    unsigned int block_id;
    BlockHeader block_header;
    merkle::Tree merkle_tree;
    std::list<Transaction> transactions;
public:
    Block();

    Block(const std::list<Transaction> &transactions, const std::string &previous_block_hash);

    const BlockHeader &getBlockHeader() const;

    const merkle::Tree &getMerkleTree() const;

    const std::list<Transaction> &getTransactions() const;

    unsigned int findTransactionIndex(const std::string &transaction_hash);

    bool checkTransaction(const std::string &transaction_hash) const;

    friend std::ostream &operator<<(std::ostream &ostream, const Block &block);
};

#endif // BLOCK_H