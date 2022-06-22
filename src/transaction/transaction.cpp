#include "transaction.h"

Transaction::Transaction() = default;

Transaction::Transaction(std::string public_key, std::string sign, const std::map<std::string, std::string> &data) {
    this->transaction_hash = generate_random_string(64);
    this->public_key = std::move(public_key);
    this->signature = std::move(sign);
    this->data.insert(std::pair<std::string, std::map<std::string, std::string>>(this->transaction_hash, data));
}

const std::string &Transaction::getTransactionHash() const {
    return transaction_hash;
}

const std::string &Transaction::getPublicKey() const {
    return public_key;
}

const std::map<std::string, std::map<std::string, std::string>> &Transaction::getData() const {
    return data;
}

std::ostream &operator<<(std::ostream &ostream, const Transaction &transaction) {
    ostream << "\t\tTransaction:"
            << "\n\t\t- transaction hash: " << transaction.transaction_hash
            << "\n\t\t- public key: " << transaction.public_key
            << "\n\t\t- signature: " << transaction.signature
            << "\n\t\t- data: ";
    for (auto const &pair: transaction.data)
        for (auto const &pair_2: pair.second)
            ostream << pair_2.first << " " << pair_2.second << ", ";
    ostream << std::endl;
    return ostream;
}