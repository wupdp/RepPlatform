#ifndef REPPLATFORM_SUBCATALOG_H
#define REPPLATFORM_SUBCATALOG_H
#include "courses.h"
#include <map>

class Subcatalog {
    string subcatalog_name;
    map<string,Course> courses;

public:
    Subcatalog();
    ~Subcatalog();
    explicit Subcatalog(string name);

    void add_course(const Course_struct &course);
    Course find_course(string name);
    void delete_course(string name);
    const string &get_subcatalog_name() const;
    const map<string, Course> &get_courses() const;
    void clear();

    friend ostream& operator<<(ostream& os, const Subcatalog& subcatalog);
};

#endif //REPPLATFORM_SUBCATALOG_H
