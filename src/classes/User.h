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
    User(int id);
    explicit User(User_data data);
    void setUsername(const std::string &username);
    void setRole(const std::string &role);
    void setData(const User_data &data);

    [[nodiscard]] const std::string &getUsername() const;
    [[nodiscard]] const std::string &getRole() const;
    [[nodiscard]] const int &getwalletid() const;

    [[nodiscard]] int checkID(std::string password) const;
    bool checkPassword(std::string password) const;
    void registerAsTeacher();
    void registerAsStudent();
    void viewNotifications();
    void viewProfile() const;
    void changePassword(std::string newPassword);
    void changePhoneNumber(std::string newNumber);
    void deactivateAccount(std::map<int, User>& usersMap);
    void logOut();
protected:
    User_data data;
    bool loggedIn{};
};


#endif //REPPLATFORM_USER_H
