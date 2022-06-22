#ifndef BLOCK_GENERATOR_H
#define BLOCK_GENERATOR_H

#include "../blocks/block.h"
#include "../utils/generate_random_string.h"
#include "transaction_generator.h"

Block generateGenesisBlock(int tx_num) {
    std::list<Transaction> transactions;
    for (int i = 0; i < tx_num; i++)
        transactions.push_back(generateTransaction());
    return {transactions, "None"};
}

Block generateBlock(const std::string &previous_block_hash, int tx_num) {
    std::list<Transaction> transactions;
    for (int i = 0; i < tx_num; i++)
        transactions.push_back(generateTransaction());
    return {transactions, previous_block_hash};
}

#endif // BLOCK_GENERATOR_H