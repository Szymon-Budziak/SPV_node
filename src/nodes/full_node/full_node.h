#ifndef FULL_NODE_H
#define FULL_NODE_H

#include "../../blockchain/blockchain.h"

class FullNode {
private:
    Blockchain blockchain;
    std::map<std::string, std::string> stateDB;
public:
    FullNode();

    explicit FullNode(const Blockchain &blockchain);

    std::string getStateDBValue(const std::string &public_key);

    void addBlock(const Block &block);

    void updateStateDB(const std::list<Transaction> &transactions);

    std::pair<merkle::Hash, std::shared_ptr<merkle::Path>> getRootAndPath(const Transaction &transaction);

    Transaction make_transaction(Wallet &from_wallet, Wallet &to_wallet, unsigned int amount);

    friend std::ostream &operator<<(std::ostream &ostream, const FullNode &full_node);
};

#endif // FULL_NODE_H