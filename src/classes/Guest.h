//
// Created by wupdp on 07.11.23.
//
#pragma once
#ifndef REPPLATFORM_GUEST_H
#define REPPLATFORM_GUEST_H


#include <string>
#include <vector>

class User;

class Guest {
public:
    Guest();
    Guest(std::vector<User>* users);  // Конструктор класса.
    ~Guest(); // Деструктор класса.

    void search_course([[maybe_unused]] std::string request_msg, std::string crit1,
                       [[maybe_unused]] std::string crit2); // Поиск курсов по критериям.
    int register_user(std::string username, std::string password); // Регистрация пользователя на сайте.
    int authorize(std::string username, std::string password); // Авторизация пользователя.
    void view_teacher_profiles(int teacher_id); // Просмотр карто}чек доступных преподавателей.

private:
    int nextUserId;

    struct UserData {
        int id = 0;
        std::string username;
        std::string password;
    };

    std::vector<User>* users;

    bool isUsernameUnique(const std::string &username);
};


#endif //REPPLATFORM_GUEST_H
