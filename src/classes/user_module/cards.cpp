//
// Created by wupdp on 25.11.23.
//

#include "../../../include/cards.h"

Cards::Cards(){
    id = 0;
    number = "000 000 000 000";
    validity = "000";
    cvc_code = 0;
    balance = 0;
}

Cards::~Cards() = default;

int Cards::getBalance() const {
    return balance;
}

void Cards::add_balance(int money) {
    balance+=money;
}

void Cards::setNumber(const std::string &number) {
    Cards::number = number;
}

void Cards::setValidity(const std::string &validity) {
    Cards::validity = validity;
}

void Cards::setCvcCode(int cvcCode) {
    cvc_code = cvcCode;
}

const std::string &Cards::getNumber() const {
    return number;
}

void Cards::setHolderName(const std::string &holderName) {
    holder_name = holderName;
}
