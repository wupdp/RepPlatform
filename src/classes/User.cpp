//
// Created by wupdp on 07.11.23.
//

#include "User.h"
#include "Guest.h"

User::User(int idD, std::string name, std::string password) {
    username = name;
    id = idD;
    wallet = 0;
    loggedIn = false;

}

User::User(int id) {

}

void User::registerAsTeacher() {

}

void User::registerAsStudent() {

}

void User::viewNotifications() {

}

void User::viewProfile() {

}

void User::editProfile(std::string profileData) {

}

void User::uploadProfilePhoto(std::string photo) {

}

void User::viewWallet() {

}

void User::replenishBalance(double amount) {

}

void User::viewSupportPage() {

}

void User::changePassword(std::string newPassword) {

}

void User::changePhoneNumber(std::string newNumber) {

}

void User::deactivateAccount() {

}

void User::logOut() {

}

bool User::checkPassword(std::string password) {
    return false;
}

int User::checkID(std::string password) {
    return this->id;
}
