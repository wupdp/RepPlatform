#include <iostream>
#include <algorithm>
#include "../../../include/guest.h"
#include "../../../include/user.h"

Guest::Guest() {
}

int Guest::authorize(string username, string password, map<int, User> &users) {
    for (const auto& userPair : users) {
        const User& user = userPair.second;
        if (user.get_username() == username && user.check_password(password)) {
            int userId = user.check_id(password);
            return userId;
        }
    }
    cout << "Авторизация не прошла для пользователя " << username << endl;
    return -1;
}

int Guest::register_user(User_data data, map<int, User> &users) {
    if (is_username_unique(data.username, users)) {
        int newId = 0;
        for (const auto& user : users) {
            if (user.first > newId) {
                newId = user.first;
            }
        }
        newId++;
        data.id = newId;
        data.role = "S";
        User newUser(data);
        (users)[newId] = newUser;
        return newId;
    } else {
        cout << "Регистрация не прошла для пользователя " << data.username << ". Такое имя уже существует." << endl;
        return -1;
    }
}

bool Guest::is_username_unique(const string &username, map<int, User> users) {
    for (const auto& userPair : users) {
        const User& user = userPair.second;
        if (user.get_username() == username) {
            return false;
        }
    }
    return true;
}

Guest::~Guest() = default;