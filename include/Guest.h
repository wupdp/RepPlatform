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

    Guest(std::map<int, User> *users);  // Конструктор класса.
    ~Guest(); // Деструктор класса.

    int register_user(User_data data); // Регистрация пользователя на сайте.
    int authorize(std::string username, std::string password); // Авторизация пользователя.
    void view_teacher_profiles(int teacher_id); // Просмотр карточек доступных преподавателей.

private:
    int nextUserId;

    struct UserData {
        int id = 0;
        std::string username;
        std::string password;
    };

    std::map<int, User> *users;

    bool is_username_unique(const std::string &username);
};


#endif //REPPLATFORM_GUEST_H
