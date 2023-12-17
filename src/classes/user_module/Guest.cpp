#include <iostream>
#include <algorithm>
#include "../../../include/Guest.h"
#include "../../../include/User.h"

Guest::Guest() {            //Basic constructor
    nextUserId = 0;
}

int Guest::authorize(std::string username, std::string password, std::map<int, User> users) {
    for (const auto& userPair : users) {
        const User& user = userPair.second;
        if (user.get_username() == username && user.check_password(password)) {
            std::cout << "Authorization successful for user_module: " << username << std::endl;
            int userId = user.check_id(password);
            delete this;
            return userId;
        }
    }
    std::cout << "Authorization failed for user_module: " << username << std::endl;
    return -1;
}

int Guest::register_user(User_data data, std::map<int, User> users) {
    if (is_username_unique(data.username, users)) {
        int newId = 0;
        for (const auto& user : users) {
            if (user.first > newId) {
                newId = user.first;
            }
        }
        newId++; // Увеличиваем максимальный ID на 1 для нового пользователя

        data.id = newId; // Присваиваем новый ID пользователю
        User newUser(data);

        (users)[newId] = newUser;
        std::cout << "Registration successful for user_module: " << data.username << std::endl;
        return newId;
    } else {
        std::cout << "Registration failed for user_module: " << data.username << ". Username already exists." << std::endl;
        return -1;
    }
}


bool Guest::is_username_unique(const std::string &username, std::map<int, User> users) {
    for (const auto& userPair : users) {
        const User& user = userPair.second;
        if (user.get_username() == username) {
            return false;
        }
    }
    return true;
}


Guest::~Guest() = default;      //Destructor
