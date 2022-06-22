#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <iostream>
#include "../utils/generate_random_string.h"

class Wallet {
private:
    std::string wallet_address;
    std::string private_key;
    unsigned int amount;
public:
    Wallet();

    explicit Wallet(unsigned int amount);

    const std::string &getWalletAddress() const;

    unsigned int getAmount() const;

    void decreaseAmount(unsigned int amount_to_dec);

    void increaseAmount(unsigned int amount_to_inc);

    friend std::ostream &operator<<(std::ostream &stream, const Wallet &wallet);
};

#endif // WALLET_H