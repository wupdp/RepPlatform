#include "../../../include/user.h"

User::User(User_data data_) {
    data = data_;
    loggedIn = false;
}

User::User(int id, map<int, User> users) {
    auto it = users.find(id);
    if (it != users.end())
        *this = it->second;
    else
        cout << "Error. No such User" << endl;
    return;
}

User::User() = default;

void User::view_notifications() {
    cout << "Notifications:" << endl;
    for (const auto &notif: data.notifications) {
        cout << notif << endl;
    }
}

void User::change_password(string newPassword) {
    if (data.password != newPassword)
        data.password = newPassword;
    else
        cout << "Введите новый пароль!" << endl;
}

void User::change_phone_number(string newNumber) {
    if (data.phone_number == newNumber)
        data.phone_number = newNumber;
    else
        cout << "Введите новый номер!" << endl;
}


void User::deactivate_account(map<int, User> &usersMap) {
    if (usersMap.find(data.id) != usersMap.end()) {
        usersMap.erase(data.id);
        cout << "Пользователь по id " << data.id << " был отключен и удален." << endl;
    } else {
        cout << "Пользователь по id " << data.id << " не найден." << endl;
    }
}

void User::logOut() {
    loggedIn = false;
}

bool User::check_password(string password) const {
    return data.password == password;
}

int User::check_id(string password) const {
    return data.id;
}

const string &User::get_username() const {
    return data.username;
}

void User::set_username(const string &username) {
    data.username = username;
}

const string &User::get_role() const {
    return data.role;
}

void User::set_role(const string &role) {
    data.role = role;
}

void User::set_data(const User_data &data_) {
    User::data = data_;
}

const User_data &User::get_data() const {
    return data;
}

const string &User::get_phonenumber() const {
    return data.phone_number;
}

const vector<string> &User::get_notifications() const {
    return data.notifications;
}

const int &User::get_id() const {
    return data.id;
}

const Cards &User::getCurrentCard() const {
    return current_card;
}

void User::setCurrentCard(const Cards &currentCard) {
    current_card = currentCard;
}
