#include "../../../include/subcatalog.h"

Subcatalog::Subcatalog() = default;

Subcatalog::~Subcatalog() = default;

Subcatalog::Subcatalog(string name) : subcatalog_name(std::move(name)) {
}

void Subcatalog::add_course(const Course_struct &course) {
    Course newCourse(course);
    courses[newCourse.get_course_name()] = newCourse;
}

Course Subcatalog::find_course(string name) {
    auto it = courses.find(name);
    if (it != courses.end()) {
        return it->second;
    }
    return Course();
}

void Subcatalog::delete_course(string name) {
    auto it = courses.find(name);
    if (it != courses.end()) {
        courses.erase(it);
    }
}

const string &Subcatalog::get_subcatalog_name() const {
    return subcatalog_name;
}

ostream& operator<<(ostream& os, const Subcatalog& subcatalog) {
    os << "================================" << endl;
    os << "Подкаталог: " << subcatalog.subcatalog_name << endl;
    os << "================================" << endl;

    for (const auto& pair : subcatalog.courses) {
        os << pair.first << endl;
    }
    return os;
}

const map<string, Course> &Subcatalog::get_courses() const {
    return courses;
}

void Subcatalog::clear() {
    for (auto &course: courses){
        course.second.clear();
    }
    courses.clear();
}