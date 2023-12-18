//
// Created by wupdp on 07.11.23.
//
#pragma once
#ifndef REPPLATFORM_GUEST_H
#define REPPLATFORM_GUEST_H


#include <string>
#include <map>

class User;
struct User_data;

class Guest {
public:
    Guest();
    ~Guest(); // Деструктор класса.

    int register_user(User_data data, std::map<int, User> &users); // Регистрация пользователя на сайте.
    int authorize(std::string username, std::string password, std::map<int, User> &users);

private:
    int nextUserId;

    bool is_username_unique(const std::string &username, std::map<int, User> users);
};


#endif //REPPLATFORM_GUEST_H
