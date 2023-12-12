//
// Created by wupdp on 12.12.23.
//

#ifndef REPPLATFORM_SUBCATALOG_H
#define REPPLATFORM_SUBCATALOG_H
#include "courses.h"
#include <map>

class Subcatalog {
    std::string subcatalog_name;
    std::vector<Course> courses;

public:
    Subcatalog();
    ~Subcatalog();
    explicit Subcatalog(const std::string &name);

    // Методы для работы с подкаталогами
    void add_course(const Course_struct &course);
    static int find_course(std::string name);
    static std::vector<std::string> list_subcatalog(std::string catalog);
    void delete_course(std::string name);
    // Другие методы для работы с курсами
    [[nodiscard]] const std::string &getSubcatalogName() const;
};


#endif //REPPLATFORM_SUBCATALOG_H
