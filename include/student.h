//
// Created by wupdp on 07.11.23.
//

#ifndef REPPLATFORM_STUDENT_H
#define REPPLATFORM_STUDENT_H

#include "User.h"

struct StudentData {
    int id;
    std::map<std::string, std::vector<std::string>> courseSchedules; // Курсы и их расписание
};


class Student : public User {
public:
    Student();

    explicit Student(int id, std::map<int, User> users);
    Student(User_data userData, StudentData studentData);
    virtual ~Student();

    void view_messages();
    void send_lesson_request(std::string teacher_id, std::string course_name, double lesson_price);

    const StudentData &getData() const;
    const std::map<std::string, std::vector<std::string>> &get_lessons() const;

    void setData(const StudentData &data);
    void set_id(const int id);
    void set_lessons(const std::map<std::string, std::vector<std::string>> lessons);

private:
    StudentData data_s;
};
//ID/Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}


#endif //REPPLATFORM_STUDENT_H
