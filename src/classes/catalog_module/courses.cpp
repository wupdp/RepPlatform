#include "../../../include/courses.h"
//#include <utility>

Course::Course(Course_struct course_stuct) : current_course(std::move(course_stuct)) {}

const string &Course::get_course_name() const {
    return current_course.name;
}

const string &Course::get_course_subcatalog() const {
    return current_course.subcatalog;
}

const vector<int> &Course::get_course_teachers() const {
    return current_course.teachers;
}

void Course::set_teachers(vector<int> teachers) {
    current_course.teachers = teachers;
}

const Course_struct &Course::get_current_course() const {
    return current_course;
}

void Course::clear() {
    current_course.teachers.clear();
}

Course::Course() = default;

Course::~Course() = default;