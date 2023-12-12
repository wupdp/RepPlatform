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

class User : public Guest {
public:
    Cards current_card;

    User();
    const std::string &getUsername() const;
    void setUsername(const std::string &username);
    const std::string &getRole() const;
    void setRole(const std::string &role);
    User(int id, std::string username, std::string password);

    explicit User(int id);
    int checkID(std::string password);
    bool checkPassword(std::string password);
    void registerAsTeacher();
    void registerAsStudent();
    void viewNotifications();
    void viewProfile();
    void editProfile(std::string profileData);
    void uploadProfilePhoto(std::string photo);
    void viewWallet();
    void replenishBalance(double amount);
    void viewSupportPage();
    void changePassword(std::string newPassword);
    void changePhoneNumber(std::string newNumber);
    void deactivateAccount();
    void logOut();
protected:

    std::string username;
    int id{};
    std::string role;
    std::vector<std::string> notifications;
    std::map<std::string, std::string> profile;
    double wallet{};
    std::string supportPage;
    std::string phoneNumber;
    bool loggedIn{};
};


#endif //REPPLATFORM_USER_H
