#ifndef REPPLATFORM_COURSES_H
#define REPPLATFORM_COURSES_H
#include "iostream"
#include "vector"

using namespace std;

struct Course_struct{
    string name;
    string subcatalog;
    vector<int> teachers;
};

class Course {
public:
    Course();
    ~Course();
    explicit Course(Course_struct course_stuct);

    const string &get_course_name() const;
    const string &get_course_subcatalog() const;
    const vector<int> &get_course_teachers() const;
    const Course_struct &get_current_course() const;

    void set_teachers(vector<int> teachers);
    void clear();
private:
    Course_struct current_course;
};

#endif //REPPLATFORM_COURSES_H
