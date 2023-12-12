//
// Created by wupdp on 25.11.23.
//

#ifndef REPPLATFORM_COURSES_H
#define REPPLATFORM_COURSES_H
#include "iostream"
#include "vector"

struct Course_struct{
    std::string name;
    std::string subcatalog;
    std::string catalog;
    std::vector<int> teachers;
};

class Course {
    Course_struct current_course;
public:
    Course();
    ~Course();
    explicit Course(const Course_struct &currentCourse);

    [[nodiscard]] const std::string &get_course_name() const;
    [[nodiscard]] const std::string &get_course_catalog() const;
    [[nodiscard]] const std::string &get_course_subcatalog() const;
    [[nodiscard]] const std::vector<int> &get_course_teachers() const;
};

#endif //REPPLATFORM_COURSES_H
