//

#include "User.h"
#include "Guest.h"

//
// Created by wupdp on 07.11.23.
User::User(User_data data_) {
    data = data_;
    loggedIn = false;
}

User::User(int id) {
    // Некоторая логика для конструктора по ID, если необходимо
}

void User::registerAsTeacher() {
    data.role = "Teacher"; // Меняем роль пользователя на "Teacher"
}

void User::registerAsStudent() {
    data.role = "Student"; // Меняем роль пользователя на "Student"
}

void User::viewNotifications() {
    // Логика для просмотра уведомлений пользователя
    for (const auto& notif : data.notifications) {
        // Вывод уведомлений в консоль или другая обработка данных
    }
}


void User::editProfile(std::string profileData) {
    // Логика для редактирования профиля пользователя
    // Обновление данных профиля на основе переданных данных
}

void User::viewSupportPage() {
    // Логика для просмотра страницы поддержки
}

void User::changePassword(std::string newPassword) {
    // Логика для изменения пароля пользователя
    data.password = newPassword; // Изменяем пароль на новый
}

void User::changePhoneNumber(std::string newNumber) {
    // Логика для изменения номера телефона пользователя
    data.phoneNumber = newNumber; // Обновляем номер телефона
}

void User::deactivateAccount() {
    // Логика для деактивации аккаунта пользователя
    // Можно изменить флаг или другие данные, чтобы указать, что аккаунт деактивирован
}

void User::logOut() {
    // Логика для выхода из аккаунта пользователя
    loggedIn = false; // Устанавливаем флаг в "false", чтобы указать, что пользователь вышел из системы
}

bool User::checkPassword(std::string password) {
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
