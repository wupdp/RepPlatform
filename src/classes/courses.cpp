//
// Created by wupdp on 25.11.23.
//

#include "courses.h"

/*int Courses::find_course(std::string name) {
    //Parsing
    //
    //
    current_course.name = "";
    current_course.catalog = "";
    current_course.undercatalog = "";
    current_course.teachers;
    return 0;
}*/

/*std::vector<std::string> Courses::list_catalog() {
    //Parsing
    //
    //
}*/

/*std::vector<std::string> Courses::list_undercatalog(std::string catalog) {
    //Parsing of 1 catalog
    //
    //
}*/

/*void Courses::add_course(std::string name) {

}*/

/*void Courses::delete_course(std::string name) {

}*/

Courses::Courses(const Course_struct &currentCourse) : current_course(currentCourse) {}

Courses::Courses() = default;

Courses::~Courses() = default;
