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
    [[nodiscard]] const std::string &getNumber() const;
    virtual ~Cards();
    void add_balance(int money);
    void setNumber(const std::string &number);
    void setCvcCode(int cvcCode);
    void setHolderName(const std::string &holderName);

    void setValidity(const std::string &validity);

private:
    int id;
    std::string number;
    std::string validity;
    std::string holder_name;
    int cvc_code;
    int balance;
};


#endif //REPPLATFORM_CARDS_H
