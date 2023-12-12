//
// Created by wupdp on 12.12.23.
//

#include "catalog.h"
#include "courses.h"

Catalog::Catalog() = default;

Catalog::~Catalog() = default;

void Catalog::addSubcatalog(const Subcatalog &subcatalog) {
    subcatalogs[subcatalog.getSubcatalogName()] = subcatalog;
}

Course Catalog::find_course(std::string name) {
    for (auto& subcatalog : subcatalogs) {
        Course course = subcatalog.second.find_course(name);
        if (!course.get_course_name().empty()) {
            return course;
        }
    }
    std::cout << "Error, course is not found\n";
    return Course();
}

std::ostream& operator<<(std::ostream& os, const Catalog& catalog) {
    for (const auto& subcatalog : catalog.subcatalogs) {
        os << subcatalog.second << std::endl;
    }
    return os;
}
