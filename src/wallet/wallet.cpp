#include "wallet.h"

Wallet::Wallet() {
    this->wallet_address = generate_random_string(64);
    this->private_key = generate_random_string(64);
    this->amount = 0;
}

Wallet::Wallet(unsigned int amount) {
    this->wallet_address = generate_random_string(64);
    this->private_key = generate_random_string(64);
    this->amount = amount;
}

const std::string &Wallet::getWalletAddress() const {
    return wallet_address;
}

unsigned int Wallet::getAmount() const {
    return amount;
}

void Wallet::decreaseAmount(unsigned int amount_to_dec) {
    if (this->amount >= amount_to_dec)
        this->amount -= amount_to_dec;
    else
        throw std::invalid_argument("Not enough amount to send");
}

void Wallet::increaseAmount(unsigned int amount_to_inc) {
    this->amount += amount_to_inc;
}

std::ostream &operator<<(std::ostream &stream, const Wallet &wallet) {
    return stream << "Wallet address is " << wallet.getWalletAddress() << " and amount is " << wallet.getAmount()
                  << "." << std::endl;
}
