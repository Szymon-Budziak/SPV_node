#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <map>
#include <iostream>
#include "../wallet/wallet.cpp"

class Transaction {
private:
    std::string transaction_hash;
    std::string public_key;
    std::string signature;
    std::map<std::string, std::map<std::string, std::string>> data;
public:
    Transaction();

    Transaction(std::string public_key, std::string signature, const std::map<std::string, std::string> &data);

    const std::string &getTransactionHash() const;

    const std::string &getPublicKey() const;

    const std::map<std::string, std::map<std::string, std::string>> &getData() const;

    friend std::ostream &operator<<(std::ostream &ostream, const Transaction &transaction);
};

#endif // TRANSACTION_H