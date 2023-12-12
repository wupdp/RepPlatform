//
// Created by wupdp on 12.12.23.
//

#include "subcatalog.h"

Subcatalog::Subcatalog() = default;

Subcatalog::~Subcatalog() = default;

Subcatalog::Subcatalog(const std::string &name) {

}

void Subcatalog::add_course(const Course_struct &course) {

}

int Subcatalog::find_course(std::string name) {
    return 0;
}

std::vector<std::string> Subcatalog::list_subcatalog(std::string catalog) {
    return {};
}

void Subcatalog::delete_course(std::string name) {

}

const std::string &Subcatalog::getSubcatalogName() const {
    return subcatalog_name;
}
