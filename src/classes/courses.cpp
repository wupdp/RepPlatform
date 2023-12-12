//
// Created by wupdp on 25.11.23.
//

#include "courses.h"

/*int Course::find_course(std::string name) {
    //Parsing
    //
    //
    current_course.name = "";
    current_course.catalog = "";
    current_course.undercatalog = "";
    current_course.teachers;
    return 0;
}*/

/*std::vector<std::string> Course::list_catalog() {
    //Parsing
    //
    //
}*/

/*std::vector<std::string> Course::list_undercatalog(std::string catalog) {
    //Parsing of 1 catalog
    //
    //
}*/

/*void Course::add_course(std::string name) {

}*/

/*void Course::delete_course(std::string name) {

}*/

Course::Course(const Course_struct &currentCourse) : current_course(currentCourse) {}

Course::Course() = default;

Course::~Course() = default;
