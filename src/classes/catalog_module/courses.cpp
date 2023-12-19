//
// Created by wupdp on 25.11.23.
//

#include "../../../include/courses.h"

#include <utility>

Course::Course(Course_struct currentCourse) : current_course(std::move(currentCourse)) {}

const std::string &Course::get_course_name() const {
    return current_course.name;
}

const std::string &Course::get_course_subcatalog() const {
    return current_course.subcatalog;
}

const std::vector<int> &Course::get_course_teachers() const {
    return current_course.teachers;
}

void Course::set_teachers(std::vector<int> teachers) {
    current_course.teachers = teachers;
}

Course::Course() = default;

Course::~Course() = default;
