//
// Created by wupdp on 07.11.23.
//

#ifndef REPPLATFORM_STUDENT_H
#define REPPLATFORM_STUDENT_H

#include "User.h"
#include "teacher.h"

struct StudentData {
    int id;
    SCHEDULE courseSchedules;
};

class Student : public User {
public:
    Student();

    explicit Student(int id, map<int, User> users);
    Student(User_data userData, StudentData studentData);
    virtual ~Student();

    void send_lesson_request(int teacher_id, string course_name, std::map<int, Teacher>);
    void sent_notif(string course, int t_id, string date);

    const StudentData &getData() const;
    const SCHEDULE &get_lessons() const;

    void setData(const StudentData &data);
    void set_id(const int id);
    void set_lessons(const SCHEDULE lessons);

private:
    StudentData data_s;
};
//ID/Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}


#endif //REPPLATFORM_STUDENT_H
