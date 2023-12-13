//

#include "User.h"
#include "Guest.h"

//
// Created by wupdp on 07.11.23.
User::User(User_data data_) {
    data = data_;
    loggedIn = false;
}

User::User(int id){

}

void User::registerAsTeacher() {
    data.role = "Teacher"; // Меняем роль пользователя на "Teacher"
}

void User::registerAsStudent() {
    data.role = "Student"; // Меняем роль пользователя на "Student"
}

void User::viewNotifications() {
    std::cout << "Notifications:" << std::endl;
    for (const auto& notif : data.notifications) {
        std::cout << notif << std::endl;
    }
}

void User::viewProfile() const {
    std::cout << "User Profile:" << std::endl;
    std::cout << "Username: " << data.username << std::endl;
    std::cout << "User ID: " << data.id << std::endl;
    std::cout << "Role: " << data.role << std::endl;

    std::cout << "Number of Notifications: " << data.notifications.size() << std::endl;

    std::cout << "Card Number: " << current_card.getNumber() << std::endl;
    std::cout << "Phone Number: " << data.phoneNumber << std::endl;
}


void User::changePassword(std::string newPassword) {
    // Логика для изменения пароля пользователя
    data.password = newPassword; // Изменяем пароль на новый
}

void User::changePhoneNumber(std::string newNumber) {
    // Логика для изменения номера телефона пользователя
    data.phoneNumber = newNumber; // Обновляем номер телефона
}

void User::deactivateAccount(std::map<int, User>& usersMap) {
    if (usersMap.find(data.id) != usersMap.end()) {
        // Удаляем пользователя из map по его ID
        usersMap.erase(data.id);
        std::cout << "User with ID " << data.id << " has been deactivated and removed." << std::endl;
    } else {
        std::cout << "User with ID " << data.id << " not found." << std::endl;
    }
}


void User::logOut() {
    // Логика для выхода из аккаунта пользователя
    loggedIn = false; // Устанавливаем флаг в "false", чтобы указать, что пользователь вышел из системы
}


bool User::checkPassword(std::string password) const {
    // Логика для проверки пароля пользователя
    return data.password == password; // Сравниваем переданный пароль с паролем пользователя
}

int User::checkID(std::string password) const {
    return data.id;
}

const std::string &User::getUsername() const {
    return data.username;
}

void User::setUsername(const std::string &name) {
    data.username = name;
}

const std::string &User::getRole() const {
    return data.role;
}

void User::setRole(const std::string &role) {
    data.role = role;
}

void User::setData(const User_data &data) {
    User::data = data;
}

const int &User::getwalletid() const {
    return data.wallet;
}

User::User() = default;
