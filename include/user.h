//
// Created by wupdp on 07.11.23.
//
#pragma once

#ifndef REPPLATFORM_USER_H
#define REPPLATFORM_USER_H

#include <string>
#include <vector>
#include <map>
#include "guest.h"
#include "cards.h"
#define SCHEDULE map<string,map<int,vector<string>>>
using namespace std;

//id/username/role/notif1,notif2,notif3,notif4../wallet_id/phone_number

struct User_data {
    string username;
    int id;
    string role;
    vector<string> notifications;

    string phone_number;
    string password;
};

class User : public Guest {
public:
    Cards current_card;

    User();
    explicit User(int id, map<int, User> users);
    explicit User(User_data data);
    void set_username(const string &username);
    void set_role(const string &role);
    void set_data(const User_data &data);

    const string &get_username() const;
    const string &get_role() const;
    const int &get_id() const;
    const string &get_phonenumber() const;
    const vector<string> &get_notifications() const;
    const User_data &get_data() const;

    int check_id(string password) const;
    bool check_password(string password) const;
    void view_notifications();
    void change_password(string newPassword);
    void change_phone_number(string newNumber);
    void deactivate_account(map<int, User>& usersMap);
    void logOut();
protected:
    User_data data;
    bool loggedIn{};
};


#endif //REPPLATFORM_USER_H
