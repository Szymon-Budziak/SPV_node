#include "block_header.h"

BlockHeader::BlockHeader() {
    timestamp = std::time(nullptr);
}

BlockHeader::BlockHeader(std::string previous_block_hash, merkle::Hash merkle_root) {
    this->previous_block_hash = std::move(previous_block_hash);
    this->merkle_root = merkle_root;
    this->timestamp = std::time(nullptr);
    this->block_hash = generate_random_string(64);
}

const merkle::Hash &BlockHeader::getMerkleRoot() const {
    return merkle_root;
}

const std::string &BlockHeader::getBlockHash() const {
    return block_hash;
}

std::ostream &operator<<(std::ostream &ostream, const BlockHeader &block_header) {
    ostream << "\t\tBlock header:"
            << "\n\t\t- block hash: " << block_header.block_hash
            << "\n\t\t- previous block hash: " << block_header.previous_block_hash
            << "\n\t\t- merkle root: " << block_header.merkle_root.to_string()
            << "\n\t\t- timestamp: " << block_header.timestamp << std::endl;
    return ostream;
}