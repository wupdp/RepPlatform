#include "classes/Guest.h"
#include "classes/User.h"
#include "classes/algorythm.h"
#include "classes/courses.h"
#include "classes/catalog.h"
#include "classes/cards.h"
#include "iostream"

int main(){
    Cards card;
    Algorithm::parse_cards(1, card);
    Catalog catalog;
    Algorithm alg;                              // Class algorithm
    std::map<std::string, Course> courses;      //map courses
    Algorithm::parse_courses(catalog);       //Ensure map
    std::cout << catalog;

    return 0;
}