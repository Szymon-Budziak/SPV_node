#include "spv_node.h"

SPVNode::SPVNode(FullNode fullNode) : full_node(std::move(fullNode)) {}

bool SPVNode::verifyMerklePath(merkle::Hash root, const std::shared_ptr<merkle::Path> &path) {
    if (path->verify(root))
        return true;
    return false;
}

std::string SPVNode::verifyTransaction(const Transaction &transaction) {
    std::pair<merkle::Hash, std::shared_ptr<merkle::Path>> root_and_path = full_node.getRootAndPath(transaction);
    if (verifyMerklePath(root_and_path.first, root_and_path.second))
        return full_node.getStateDBValue(transaction.getPublicKey());
    throw std::invalid_argument("There is no such transaction.\n");
}