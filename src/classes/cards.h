//
// Created by wupdp on 25.11.23.
//

#ifndef REPPLATFORM_CARDS_H
#define REPPLATFORM_CARDS_H
#include "iostream"

class Cards {
public:
    Cards();

    [[nodiscard]] int getBalance() const;
    virtual ~Cards();
    void add_balance(int money);

private:
    int id;
    std::string number;
    std::string validity;
    int cvc_code;
    int balance;
};


#endif //REPPLATFORM_CARDS_H
