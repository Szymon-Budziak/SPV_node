#include "src/wallet/wallet.h"
#include "src/generators/blockchain_generator.h"
#include "src/nodes/full_node/full_node.cpp"
#include "src/nodes/spv_node/spv_node.cpp"

int main(int argc, char *argv[]) {
    // Alice wallet
    Wallet alice_wallet(100);

    // Joe wallet
    Wallet joe_wallet(0);

    std::cout << alice_wallet;
    std::cout << joe_wallet;
    // Generate random blockchain
    Blockchain blockchain = generateBlockchain(2);

    // Create full node
    FullNode full_node(blockchain);
    // Create new transaction
    Transaction new_transaction = full_node.make_transaction(alice_wallet, joe_wallet, 30);

    std::cout << full_node;
    std::cout << alice_wallet;
    std::cout << joe_wallet;

    // Create spv node
    SPVNode spvNode(full_node);
    std::string stateDb_value = spvNode.verifyTransaction(new_transaction);
    std::cout << stateDb_value;
}