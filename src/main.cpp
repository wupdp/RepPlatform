#include "classes/Guest.h"
#include "classes/User.h"
#include "classes/algorythm.h"
#include "classes/courses.h"
#include "iostream"

int main(){

    Algorithm alg;                              // Class algorithm
    std::map<std::string, Course> courses;      //map courses
    Algorithm::parse_courses(courses);       //Ensure map
    std::cout << courses.size();

    return 0;
}