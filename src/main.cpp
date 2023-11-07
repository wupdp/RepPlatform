#include "classes/Guest.h"
#include "classes/User.h"
#include "iostream"
int main(){
    std::vector<User> users;
    Guest person(&users);
    int newID = person.register_user("name", "password123");
    std::cout << "Number of users: "<<users.size();

    return 0;
}