//
// Created by wupdp on 25.11.23.
//

#include "cards.h"

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
