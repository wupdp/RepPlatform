#include "../../../include/User.h"

User::User(User_data data_) {
    data = data_;
    loggedIn = false;
}

User::User(int id, map<int, User> users){
    auto it = users.find(id);

    if (it != users.end())
        *this = it->second;
    else
        ///
        return;
}

User::User() = default;

void User::view_notifications() {
    cout << "Notifications:" << endl;
    for (const auto& notif : data.notifications) {
        cout << notif << endl;
    }
}


void User::view_profile() const {
    cout << "User Profile:" << endl;
    cout << "Username: " << data.username << endl;
    cout << "User ID: " << data.id << endl;
    cout << "Role: " << data.role << endl;

    cout << "Number of Notifications: " << data.notifications.size() << endl;

    cout << "Card Number: " << current_card.getNumber() << endl;
    cout << "Phone Number: " << data.phoneNumber << endl;
}

void User::change_password(string newPassword) {
    // Логика для изменения пароля пользователя
    data.password = newPassword; // Изменяем пароль на новый
}

void User::change_phone_number(string newNumber) {
    // Логика для изменения номера телефона пользователя
    data.phoneNumber = newNumber; // Обновляем номер телефона
}


void User::deactivate_account(map<int, User>& usersMap) {
    if (usersMap.find(data.id) != usersMap.end()) {
        // Удаляем пользователя из map по его ID
        usersMap.erase(data.id);
        cout << "User with ID " << data.id << " has been deactivated and removed." << endl;
    } else {
        cout << "User with ID " << data.id << " not found." << endl;
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

const int &User::get_wallet_id() const {
    return data.wallet;
}

const User_data &User::get_data() const {
    return data;
}

const string &User::get_phonenumber() const {
    return data.phoneNumber;
}

const vector<string> &User::get_notifications() const {
    return data.notifications;
}

const int &User::get_id() const {
    return data.id;
}