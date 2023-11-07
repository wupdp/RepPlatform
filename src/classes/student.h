//
// Created by wupdp on 07.11.23.
//

#ifndef REPPLATFORM_STUDENT_H
#define REPPLATFORM_STUDENT_H

#include "User.h"

class Student : public User {
public:
    Student(std::string username, std::string password);

    void view_messages();
    void send_message(std::string message);
    void send_lesson_request(std::string teacher_id, std::string course_name, double lesson_price);
    void view_lesson_schedule();

private:
    std::vector<std::string> lesson_requests;
    std::vector<std::string> lesson_schedule;
};


#endif //REPPLATFORM_STUDENT_H
