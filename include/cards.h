#ifndef REPPLATFORM_CARDS_H
#define REPPLATFORM_CARDS_H
#include "iostream"

using namespace std;

class Cards {
public:
    Cards();
    virtual ~Cards();

    int get_balance() const;
    int get_id() const;
    const string &get_number() const;
    const string &get_validity() const;
    const string &get_HolderName() const;
    int get_cvc() const;

    void add_balance(int money);
    void set_number(const string &number);
    void set_cvc(int cvcCode);
    void set_HolderName(const string &holderName);
    void set_validity(const string &validity);

private:
    int id;
    string number;
    string validity;
    string holder_name;
    int cvc_code;
    int balance;
};

#endif //REPPLATFORM_CARDS_H