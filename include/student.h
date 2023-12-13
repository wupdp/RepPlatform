//
// Created by wupdp on 07.11.23.
//

#ifndef REPPLATFORM_STUDENT_H
#define REPPLATFORM_STUDENT_H

#include "User.h"

class Student : public User {
public:
    explicit Student(int id);
    virtual ~Student();

    void view_messages();
    void send_lesson_request(std::string teacher_id, std::string course_name, double lesson_price);
    void view_lesson_schedule();
private:
    std::vector<std::string> lesson_requests;
    std::vector<std::string> lesson_schedule;
    void get_lessons();
};


#endif //REPPLATFORM_STUDENT_H
