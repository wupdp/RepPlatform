#include <iostream>
#include "User.h"
#include "teacher.h"
#include "student.h"
#include "courses.h"
#include "subcatalog.h"
#include "catalog.h"
#include "cards.h"
#include "algorythm.h"

class Interface {
private:
    Catalog catalog;
    std::map<int, User> usersMap;
    std::map<int, Teacher> teachersMap;
    std::map<int, Student> studentsMap;
    Algorithm alg;

    void displayCourses();
    void displayTeachers();
    void displaySubcatalogs();
public:
    Interface();
    virtual ~Interface();
    void displayMenu();
    void handleUserInput();
};
