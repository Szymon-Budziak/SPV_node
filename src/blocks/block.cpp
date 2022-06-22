#include "block.h"

unsigned int Block::block_counter = 0;

Block::Block() = default;

Block::Block(const std::list<Transaction> &transactions, const std::string &previous_block_hash) {
    for (auto &t: transactions) {
        this->transactions.push_back(t);
        this->merkle_tree.insert(t.getTransactionHash());
    }
    this->block_id = block_counter++;
    this->block_header = BlockHeader(previous_block_hash, this->merkle_tree.root());
}

const BlockHeader &Block::getBlockHeader() const {
    return block_header;
}

const merkle::Tree &Block::getMerkleTree() const {
    return merkle_tree;
}

const std::list<Transaction> &Block::getTransactions() const {
    return transactions;
}

unsigned int Block::findTransactionIndex(const std::string &transaction_hash) {
    unsigned int index = 0;
    for (auto &t: transactions) {
        if (t.getTransactionHash() == transaction_hash)
            return index;
        index++;
    }
    return -1;
}

bool Block::checkTransaction(const std::string &transaction_hash) const {
    for (auto &t: transactions) {
        if (transaction_hash == t.getTransactionHash())
            return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &ostream, const Block &block) {
    ostream << "Block:"
            << "\n\t- block id: " << block.block_id
            << "\n\t- block header:\n" << block.block_header
            << "\t- transactions:\n";
    for (auto &t: block.transactions)
        ostream << t;
    ostream << std::endl;
    return ostream;
}

