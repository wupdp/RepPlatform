//
// Created by wupdp on 12.12.23.
//

#ifndef REPPLATFORM_SUBCATALOG_H
#define REPPLATFORM_SUBCATALOG_H
#include "courses.h"
#include <map>

class Subcatalog {
    std::string subcatalog_name;
    std::map<std::string,Course> courses;

public:
    Subcatalog();
    ~Subcatalog();
    explicit Subcatalog(std::string name);

    void add_course(const Course_struct &course);
    Course find_course(std::string name);
    void delete_course(std::string name);
    [[nodiscard]] const std::string &getSubcatalogName() const;
    friend std::ostream& operator<<(std::ostream& os, const Subcatalog& subcatalog);
};


#endif //REPPLATFORM_SUBCATALOG_H
