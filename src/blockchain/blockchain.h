#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <list>
#include <iostream>
#include "../blocks/block.cpp"
#include "../utils/generate_random_string.h"

class Blockchain {
private:
    std::list<Block> blocks;
public:
    Blockchain();

    void addBlock(const Block &block);

    const std::list<Block> &getBlocks() const;

    Block getLastBlock();

    friend std::ostream &operator<<(std::ostream &stream, const Blockchain &blockchain);
};

#endif // BLOCKCHAIN_H

