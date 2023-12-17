//
// Created by wupdp on 12.12.23.
//

#include "../../../include/catalog.h"
#include "../../../include/courses.h"

Catalog::Catalog() = default;

Catalog::~Catalog() = default;

void Catalog::addSubcatalog(const std::string& undercatalog_name) {
    if (subcatalogs.find(undercatalog_name) == subcatalogs.end()) {
        Subcatalog new_subcatalog(undercatalog_name);
        subcatalogs[undercatalog_name] = new_subcatalog;
    } else {
        std::cout << "Subcatalog " << undercatalog_name << " already exists!" << std::endl;
    }
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

bool Catalog::hasSubcatalog(const std::string& subcatalog) const {
    return subcatalogs.find(subcatalog) != subcatalogs.end();
}

Subcatalog &Catalog::getSubcatalog(const std::string &subcatalogName) {
        return subcatalogs[subcatalogName];
}

void Catalog::display_courses() {
    if (subcatalogs.empty()) {
        std::cout << "Каталог курсов пуст." << std::endl;
        return;
    }

    for (const auto& pair : subcatalogs) {
        const Subcatalog& subcatalog = pair.second;
        std::cout << subcatalog; // Используем оператор <<
    }
}

std::map<std::string, Subcatalog> Catalog::getSubcatalogs() {
    return subcatalogs;
}


