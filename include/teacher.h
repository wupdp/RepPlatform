//
// Created by wupdp on 07.11.23.
//

#ifndef REPPLATFORM_TEACHER_H
#define REPPLATFORM_TEACHER_H
#include "iostream"
#include "vector"
#include "User.h"

class Teacher : public User {
public:
    Teacher();
    explicit Teacher(int id);
    virtual ~Teacher();
    void get_lesson_request(std::string student_id, std::string course_name, double lesson_price);
    void view_lesson_schedule();
    void edit_lesson_schedule();
    void edit_profile();
private:
    std::vector<std::string> lesson_requests;
    std::vector<std::string> lesson_schedule;
    void get_lessons();
};


#endif //REPPLATFORM_TEACHER_H
