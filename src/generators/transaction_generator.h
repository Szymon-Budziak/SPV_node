#ifndef TRANSACTION_GENERATOR_H
#define TRANSACTION_GENERATOR_H

#include "../transaction/transaction.cpp"

Transaction generateTransaction() {
    std::string public_key, signature;
    public_key = generate_random_string(5);
    std::map<std::string, std::string> data;
    data.insert(std::pair<std::string, std::string>(public_key, std::to_string(rand() % 100)));
    signature = public_key;
    return {public_key, signature, data};
}

#endif // TRANSACTION_GENERATOR_H