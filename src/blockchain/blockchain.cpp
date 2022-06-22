#include "blockchain.h"

Blockchain::Blockchain() = default;

void Blockchain::addBlock(const Block &block) {
    blocks.push_back(block);
}

const std::list<Block> &Blockchain::getBlocks() const {
    return blocks;
}

Block Blockchain::getLastBlock() {
    return blocks.back();
}

std::ostream &operator<<(std::ostream &ostream, const Blockchain &blockchain) {
    ostream << "Blockchain:"
            << "\n- blocks number: " << blockchain.blocks.size()
            << "\n- blocks:\n";
    for (auto &b: blockchain.blocks)
        ostream << "\t" << b;
    ostream << std::endl;
    return ostream;
}
