//
// Created by wupdp on 12.12.23.
//

#include "subcatalog.h"

Subcatalog::Subcatalog() = default;

Subcatalog::~Subcatalog() = default;

Subcatalog::Subcatalog(const std::string &name) : subcatalog_name(name) {
    // Инициализация других членов класса, если необходимо
}

void Subcatalog::add_course(const Course_struct &course) {
    Course newCourse(course);
    courses.push_back(newCourse);
}

Course Subcatalog::find_course(std::string name) {
    for (const auto& course : courses) {
        if (course.get_course_name() == name) {
            return course;
        }
    }
    return Course(); // Вернуть пустой объект Course, если курс не найден
}

void Subcatalog::delete_course(std::string name) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (it->get_course_name() == name) {
            courses.erase(it);
            break;
        }
    }
}

const std::string &Subcatalog::getSubcatalogName() const {
    return subcatalog_name;
}

std::ostream& operator<<(std::ostream& os, const Subcatalog& subcatalog) {
    os << "Subcatalog: " << subcatalog.subcatalog_name << std::endl;
    for (const auto& course : subcatalog.courses) {
        os << "Course Name: " << course.get_course_name() << std::endl;
        // Вывод других данных о курсе, если необходимо
    }
    return os;
}