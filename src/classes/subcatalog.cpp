//
// Created by wupdp on 12.12.23.
//

#include "subcatalog.h"

//#include <utility>

Subcatalog::Subcatalog() = default;

Subcatalog::~Subcatalog() = default;

Subcatalog::Subcatalog(std::string name) : subcatalog_name(std::move(name)) {
}

void Subcatalog::add_course(const Course_struct &course) {
    Course newCourse(course);
    courses[newCourse.get_course_name()] = newCourse;
}

Course Subcatalog::find_course(std::string name) {
    auto it = courses.find(name);
    if (it != courses.end()) {
        return it->second; // Возвращаем найденный курс
    }
    return Course(); // Вернуть пустой объект Course, если курс не найден
}

void Subcatalog::delete_course(std::string name) {
    auto it = courses.find(name);
    if (it != courses.end()) {
        courses.erase(it); // Удаляем курс, если найден
    }
}

const std::string &Subcatalog::getSubcatalogName() const {
    return subcatalog_name;
}

std::ostream& operator<<(std::ostream& os, const Subcatalog& subcatalog) {
    os << "Subcatalog: " << subcatalog.subcatalog_name << std::endl;
    for (const auto& pair : subcatalog.courses) {
        os << "Course Name: " << pair.first << std::endl;
    }
    return os;
}
