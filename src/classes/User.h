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

//id/username/role/{notif1/notif2/notif3/notif4..}/wallet_id/phoneNumber
struct User_data {
    std::string username;
    int id{};
    std::string role;
    std::vector<std::string> notifications;
    int wallet;
    std::string phoneNumber;
    std::string password;

};

class User : public Guest {
public:
    Cards current_card;

    User();
    explicit User(int id);
    explicit User(User_data data);
    void set_username(const std::string &username);
    void set_role(const std::string &role);
    void set_data(const User_data &data);

    [[nodiscard]] const std::string &get_username() const;
    [[nodiscard]] const std::string &get_role() const;
    [[nodiscard]] const int &get_wallet_id() const;

    [[nodiscard]] int check_id(std::string password) const;
    [[nodiscard]] bool check_password(std::string password) const;
    void register_as_teacher();
    void register_as_student();
    void view_notifications();
    void view_profile() const;
    void change_password(std::string newPassword);
    void change_phone_number(std::string newNumber);
    void deactivate_account(std::map<int, User>& usersMap);
    void logOut();
protected:
    User_data data;
    bool loggedIn{};
};


#endif //REPPLATFORM_USER_H
