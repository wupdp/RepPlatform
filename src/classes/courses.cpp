//
// Created by wupdp on 25.11.23.
//

#include "courses.h"

Course::Course(const Course_struct &currentCourse) : current_course(currentCourse) {}

const std::string &Course::get_course_name() const {
    return current_course.name;
}

const std::string &Course::get_course_catalog() const {
    return current_course.catalog;
}

const std::string &Course::get_course_subcatalog() const {
    return current_course.subcatalog;
}

const std::vector<int> &Course::get_course_teachers() const {
    return current_course.teachers;
}

Course::Course() = default;

Course::~Course() = default;
