#ifndef BLOCKCHAIN_GENERATOR_H
#define BLOCKCHAIN_GENERATOR_H

#include "../blockchain/blockchain.cpp"
#include "block_generator.h"

Blockchain generateBlockchain(int number_of_blocks) {
    Blockchain blockchain;
    std::string previous_block_hash;
    Block block;
    for (int i = 0; i < number_of_blocks; i++) {
        if (i == 0)
            block = generateGenesisBlock(3);
        else
            block = generateBlock(previous_block_hash, 3);
        previous_block_hash = block.getBlockHeader().getBlockHash();
        blockchain.addBlock(block);
    }
    return blockchain;
}

#endif // BLOCKCHAIN_GENERATOR_H