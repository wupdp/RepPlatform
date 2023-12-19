#include "../../../include/cards.h"

Cards::Cards() {
    id = 0;
    number = "000 000 000 000";
    validity = "000";
    cvc_code = 0;
    balance = 0;
}

Cards::~Cards() = default;

int Cards::get_balance() const {
    return balance;
}

void Cards::add_balance(int money) {
    balance += money;
}

void Cards::set_number(const string &number_) {
    number = number_;
}

void Cards::set_validity(const string &validity_) {
    validity = validity_;
}

void Cards::set_cvc(int code) {
    cvc_code = code;
}

const string &Cards::get_number() const {
    return number;
}

void Cards::set_HolderName(const string &name) {
    holder_name = name;
}

int Cards::get_id() const {
    return id;
}

const string &Cards::get_validity() const {
    return validity;
}

const string &Cards::get_HolderName() const {
    return holder_name;
}

int Cards::get_cvc() const {
    return cvc_code;
}