#pragma once
#ifndef REPPLATFORM_GUEST_H
#define REPPLATFORM_GUEST_H


#include <string>
#include <map>

using namespace std;

class User;
struct User_data;

class Guest {
public:
    Guest();
    ~Guest();

    int register_user(User_data data, map<int, User> &users);
    int authorize(string username, std::string password, map<int, User> &users);

private:
    bool is_username_unique(const string &username, map<int, User> users);
};


#endif //REPPLATFORM_GUEST_H
