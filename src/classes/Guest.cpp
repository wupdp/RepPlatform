#include <iostream>
#include <algorithm>
#include "Guest.h"
#include "User.h"

Guest::Guest() {            //Basic constructor
    nextUserId = 0;
    users = nullptr;
}

Guest::Guest(std::map<int, User> *usersD) {    //Link constructor
    users = usersD;
    nextUserId = 0;
}

void Guest::view_teacher_profiles(int teacher_id) {     //Catalog o teachers

}

int Guest::authorize(std::string username, std::string password) {
    for (const auto& userPair : *users) {
        const User& user = userPair.second;
        if (user.get_username() == username && user.check_password(password)) {
            std::cout << "Authorization successful for user: " << username << std::endl;
            int userId = user.check_id(password);
            delete this;
            return userId;
        }
    }
    std::cout << "Authorization failed for user: " << username << std::endl;
    return -1;
}

int Guest::register_user(User_data data) {
    if (is_username_unique(data.username)) {
        User newUser(data);
        (*users)[data.id] = newUser;
        std::cout << "Registration successful for user: " << data.username << std::endl;
        return data.id;
    } else {
        std::cout << "Registration failed for user: " << data.username << ". Username already exists." << std::endl;
        return -1;
    }
}

bool Guest::is_username_unique(const std::string &username) {
    for (const auto& userPair : *users) {
        const User& user = userPair.second;
        if (user.get_username() == username) {
            return false;
        }
    }
    return true;
}


Guest::~Guest() = default;      //Destructor
