#include <iostream>
#include <algorithm>
#include "Guest.h"
#include "User.h"

Guest::Guest() {            //Basic constructor
    nextUserId = 0;
    users = nullptr;
}

Guest::Guest(std::vector<User> *usersD) {    //Link constructor
    users = usersD;
    nextUserId = 0;
}

void Guest::view_teacher_profiles(int teacher_id) {     //Catalog o teachers

}

int Guest::authorize(std::string username, std::string password) {          //Authorisation
    for (User &user: *users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            std::cout << "Authorization successful for user: " << username << std::endl;

            int userId = user.checkID(password);
            delete this;            // Удаляем объект Guest после успешной авторизации

            return userId;
        }
    }

    std::cout << "Authorization failed for user: " << username << std::endl;
    return -1;
}

int Guest::register_user(std::string username, std::string password) {      //Registration
    //LOGIC
    //
    if (isUsernameUnique(username)) {
        User *newUser = new User(nextUserId, username, password);
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
Guest::search_course([[maybe_unused]] std::string request_msg, std::string crit1, [[maybe_unused]] std::string crit2) { //Search course
    //search in map
}

Guest::~Guest() = default;      //Destructor

bool Guest::isUsernameUnique(const std::string &username) {
    return std::all_of(users->begin(), users->end(), [username](const User &user) {
        return user.getUsername() != username;
    });
}