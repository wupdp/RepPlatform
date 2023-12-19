//
// Created by wupdp on 07.11.23.
//
#pragma once

#ifndef REPPLATFORM_USER_H
#define REPPLATFORM_USER_H

#include <string>
#include <vector>
#include <map>
#include "Guest.h"
#include "cards.h"
using namespace std;
#define SCHEDULE map<string,map<int,vector<string>>>
//id/username/role/{notif1/notif2/notif3/notif4..}/wallet_id/phoneNumber
struct User_data {
    string username;
    int id{};
    string role;
    vector<string> notifications;
    int wallet;
    string phoneNumber;
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

    [[nodiscard]] const string &get_username() const;
    [[nodiscard]] const string &get_role() const;
    [[nodiscard]] const int &get_wallet_id() const;

    const int &get_id() const;
    [[nodiscard]] const string &get_phonenumber() const;
    [[nodiscard]] const vector<string> &get_notifications() const;

    const User_data &get_data() const;

    [[nodiscard]] int check_id(string password) const;
    [[nodiscard]] bool check_password(string password) const;
    void view_notifications();
    void view_profile() const;
    void change_password(string newPassword);
    void change_phone_number(string newNumber);
    void deactivate_account(map<int, User>& usersMap);
    void logOut();
protected:
    User_data data;
    bool loggedIn{};
};


#endif //REPPLATFORM_USER_H
