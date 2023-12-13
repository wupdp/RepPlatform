#include "../include/Guest.h"
#include "../include/User.h"
#include "../include/algorythm.h"
#include "../include/courses.h"
#include "../include/catalog.h"
#include "../include/cards.h"
#include "iostream"

int main(){
    Cards card;
    Algorithm::parse_cards(1, card);
    Catalog catalog;
    Algorithm alg;                              // Class algorithm
    Algorithm::parse_courses(catalog);       //Ensure map
    std::cout << catalog;
    std::map<int, User> users;
    Algorithm::parse_users(users);
    users[1].view_profile();
    users[1].deactivate_account(users);
    users[1].view_profile();

    return 0;
}