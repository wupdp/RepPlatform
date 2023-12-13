//

#include "../../../include/User.h"
#include "../../../include/Guest.h"

//
// Created by wupdp on 07.11.23.
User::User(User_data data_) {
    data = data_;
    loggedIn = false;
}

User::User(int id){

}

User::User() = default;

void User::register_as_teacher() {
    data.role = "Teacher"; // Меняем роль пользователя на "Teacher"
}

void User::register_as_student() {
    data.role = "Student"; // Меняем роль пользователя на "Student"
}

void User::view_notifications() {
    std::cout << "Notifications:" << std::endl;
    for (const auto& notif : data.notifications) {
        std::cout << notif << std::endl;
    }
}


void User::view_profile() const {
    std::cout << "User Profile:" << std::endl;
    std::cout << "Username: " << data.username << std::endl;
    std::cout << "User ID: " << data.id << std::endl;
    std::cout << "Role: " << data.role << std::endl;

    std::cout << "Number of Notifications: " << data.notifications.size() << std::endl;

    std::cout << "Card Number: " << current_card.getNumber() << std::endl;
    std::cout << "Phone Number: " << data.phoneNumber << std::endl;
}

void User::change_password(std::string newPassword) {
    // Логика для изменения пароля пользователя
    data.password = newPassword; // Изменяем пароль на новый
}

void User::change_phone_number(std::string newNumber) {
    // Логика для изменения номера телефона пользователя
    data.phoneNumber = newNumber; // Обновляем номер телефона
}


void User::deactivate_account(std::map<int, User>& usersMap) {
    if (usersMap.find(data.id) != usersMap.end()) {
        // Удаляем пользователя из map по его ID
        usersMap.erase(data.id);
        std::cout << "User with ID " << data.id << " has been deactivated and removed." << std::endl;
    } else {
        std::cout << "User with ID " << data.id << " not found." << std::endl;
    }
}


void User::logOut() {
    loggedIn = false;
}

bool User::check_password(std::string password) const {
    return data.password == password;
}

int User::check_id(std::string password) const {
    return data.id;
}

const std::string &User::get_username() const {
    return data.username;
}

void User::set_username(const std::string &username) {
    data.username = username;
}

const std::string &User::get_role() const {
    return data.role;
}

void User::set_role(const std::string &role) {
    data.role = role;
}

void User::set_data(const User_data &data_) {
    User::data = data_;
}

const int &User::get_wallet_id() const {
    return data.wallet;
}
