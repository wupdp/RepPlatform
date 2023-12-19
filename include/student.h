#ifndef REPPLATFORM_STUDENT_H
#define REPPLATFORM_STUDENT_H

#include "user.h"
#include "teacher.h"

struct Student_data {
    int id;
    SCHEDULE Schedules;
};

class Student : public User {
public:
    Student();
    explicit Student(int id, map<int, User> users);
    explicit Student(User_data userData, Student_data studentData);
    virtual ~Student();

    void send_lesson_request(int teacher_id, string course_name, map<int, Teacher>);
    void sent_notif(string course, int t_id, string date);

    const Student_data &get_data_s() const;
    const SCHEDULE &get_lessons() const;

    void set_data_s(const Student_data &data);
    void set_id(const int id);
    void set_lessons(const SCHEDULE lessons);
private:
    Student_data data_s;
};
//ID/Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}Курс{ID преподавателя:даты ближайших занятий в виде день.месяц день.месяц}

#endif //REPPLATFORM_STUDENT_H
