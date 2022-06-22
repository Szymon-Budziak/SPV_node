#ifndef BLOCK_HEADER_H
#define BLOCK_HEADER_H

#include <string>
#include <iostream>
#include <ctime>
#include "../merkle_tree/merkle_tree.h"
#include "../utils/generate_random_string.h"

class BlockHeader {
private:
    std::string previous_block_hash;
    merkle::Hash merkle_root;
    std::time_t timestamp;
    std::string block_hash;
public:
    BlockHeader();

    BlockHeader(std::string previous_block_hash, merkle::Hash merkle_root);

    const merkle::Hash &getMerkleRoot() const;

    const std::string &getBlockHash() const;

    friend std::ostream &operator<<(std::ostream &ostream, const BlockHeader &block_header);
};

#endif // BLOCK_HEADER_H