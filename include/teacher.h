#ifndef REPPLATFORM_TEACHER_H
#define REPPLATFORM_TEACHER_H
#include "iostream"
#include "vector"
#include "user.h"
using namespace std;

struct Teacher_data {
    int id;
    SCHEDULE schedules;
    int experience;
    double rating;
};

class Teacher : public User {
public:
    Teacher();
    explicit Teacher(int id, map<int, User> users);
    explicit Teacher(const User_data &userData, Teacher_data teacherData);
    virtual ~Teacher();

    void set_tdata(const Teacher_data &data);
    void set_id(int);
    void set_courses(SCHEDULE);
    void set_exp(int);
    void set_rate(double);

    const Teacher_data &get_tdata() const;
    SCHEDULE &get_courses();
    int &get_exp();
    double &get_rate();

    void get_lesson_request(int student_id, string course_name);

private:
    Teacher_data data_t;
};
//ID/{Курс{ID ученика:даты ближайших занятий в виде день.месяц день.месяц}Курс{ID ученика:даты ближайших занятий в виде день.месяц день.месяц}}/стаж/рейтинг

#endif //REPPLATFORM_TEACHER_H
