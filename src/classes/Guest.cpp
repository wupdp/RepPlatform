//
// Created by wupdp on 07.11.23.
//
#include <iostream>
#include <algorithm>
#include "Guest.h"
#include "User.h"

Guest::Guest() {
    nextUserId = 0;
    users = nullptr;
}

Guest::Guest(std::vector<User>* usersD){
    users = usersD;
    nextUserId = 0;
}

void Guest::view_teacher_profiles(int teacher_id) {

}

int Guest::authorize(std::string username, std::string password) {
    for (User& user : *users) {
        if (user.username == username && user.checkPassword(password)) {
            std::cout << "Authorization successful for user: " << username << std::endl;

            int userId = user.checkID(password);
            delete this; // Удаляем объект Guest после успешной авторизации

            return userId;
        }
    }

    std::cout << "Authorization failed for user: " << username << std::endl;
    return -1;
}

int Guest::register_user(std::string username, std::string password) {
    //LOGIC
    //
    if (isUsernameUnique(username)) {
        User* newUser = new User(nextUserId, username, password);
        (*users).push_back(*newUser);

        std::cout << "Registration successful for user: " << username << std::endl;

        nextUserId++;

        return nextUserId - 1;
    } else {
        std::cout << "Registration failed for user: " << username << ". Username already exists." << std::endl;

        return -1;
    }
}

void
Guest::search_course([[maybe_unused]] std::string request_msg, std::string crit1, [[maybe_unused]] std::string crit2) {

}

Guest::~Guest() = default;

bool Guest::isUsernameUnique(const std::string& username) {
    return std::all_of(users->begin(), users->end(), [username](const User& user) {
        return user.username != username;
    });
}