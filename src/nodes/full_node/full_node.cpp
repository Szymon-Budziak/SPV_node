#include "full_node.h"

FullNode::FullNode() = default;

FullNode::FullNode(const Blockchain &blockchain) {
    this->blockchain = blockchain;
    for (auto &b: blockchain.getBlocks())
        updateStateDB(b.getTransactions());
}

std::string FullNode::getStateDBValue(const std::string &public_key) {
    auto it = stateDB.find(public_key);
    if (it == stateDB.end())
        return "";
    return it->second;
}

void FullNode::addBlock(const Block &block) {
    blockchain.addBlock(block);
    updateStateDB(block.getTransactions());
}

void FullNode::updateStateDB(const std::list<Transaction> &transactions) {
    for (auto &t: transactions) {
        if (stateDB.find(t.getPublicKey()) == stateDB.end())
            for (auto &pair: t.getData())
                for (auto &pair_2: pair.second)
                    stateDB.insert(std::pair<std::string, std::string>(pair_2.first, pair_2.second));
        else
            for (auto &pair: t.getData())
                for (auto &pair_2: pair.second)
                    stateDB.at(pair_2.first) = pair_2.second;
    }
}

std::pair<merkle::Hash, std::shared_ptr<merkle::Path>> FullNode::getRootAndPath(const Transaction &transaction) {
    std::list<Block> blocks = blockchain.getBlocks();
    std::pair<merkle::Hash, std::shared_ptr<merkle::Path>> root_and_path;
    for (auto &b: blocks) {
        if (b.checkTransaction(transaction.getTransactionHash())) {
            merkle::Tree tree = b.getMerkleTree();
            unsigned int index = b.findTransactionIndex(transaction.getTransactionHash());
            root_and_path.first = b.getBlockHeader().getMerkleRoot();
            root_and_path.second = tree.path(index);
            break;
        }
    }
    return root_and_path;
}

Transaction FullNode::make_transaction(Wallet &from_wallet, Wallet &to_wallet, unsigned int amount) {
    std::string from_wallet_address, sig, to_wallet_address;
    from_wallet.decreaseAmount(amount);
    to_wallet.increaseAmount(amount);

    from_wallet_address = from_wallet.getWalletAddress();
    sig = from_wallet.getWalletAddress();
    to_wallet_address = to_wallet.getWalletAddress();

    std::map<std::string, std::string> data;
    data.insert(std::pair<std::string, std::string>(from_wallet_address, std::to_string(from_wallet.getAmount())));
    data.insert(std::pair<std::string, std::string>(to_wallet_address, std::to_string(to_wallet.getAmount())));
    // Transaction
    std::list<Transaction> transactions;
    Transaction transaction(from_wallet_address, sig, data);
    transactions.push_back(transaction);
    // Block
    Block block(transactions, blockchain.getLastBlock().getBlockHeader().getBlockHash());
    addBlock(block);
    return transaction;
}

std::ostream &operator<<(std::ostream &ostream, const FullNode &full_node) {
    ostream << "State db:";
    for (auto &pair: full_node.stateDB)
        ostream << "\n\t" << pair.first << " -> " << pair.second;
    ostream << "\n";
    std::cout << full_node.blockchain;
    ostream << std::endl;
    return ostream;
}