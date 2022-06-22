#ifndef SPV_NODE_H
#define SPV_NODE_H

#include "../full_node/full_node.h"

class SPVNode {
private:
    FullNode full_node;
public:
    explicit SPVNode(FullNode fullNode);

    static bool verifyMerklePath(merkle::Hash root, const std::shared_ptr<merkle::Path>& path);

    std::string verifyTransaction(const Transaction &transaction);
};

#endif // SPV_NODE_H