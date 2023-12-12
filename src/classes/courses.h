//
// Created by wupdp on 25.11.23.
//

#ifndef REPPLATFORM_COURSES_H
#define REPPLATFORM_COURSES_H
#include "iostream"
#include "vector"

struct Course_struct{
    std::string name;
    std::string undercatalog;
    std::string catalog;
    std::vector<int> teachers;
};

class Course {
    Course_struct current_course;
public:
    Course();
    ~Course();
    explicit Course(const Course_struct &currentCourse);

    //
};

#endif //REPPLATFORM_COURSES_H
