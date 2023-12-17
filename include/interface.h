#include <iostream>
#include "User.h"
#include "teacher.h"
#include "student.h"
#include "courses.h"
#include "subcatalog.h"
#include "catalog.h"
#include "cards.h"
#include "algorythm.h"

enum UserType { GUEST, USER, STUDENT, TEACHER };

class Interface {
private:
    Catalog catalog;
    std::map<int, User> usersMap;
    std::map<int, Teacher> teachersMap;
    std::map<int, Student> studentsMap;
    Algorithm alg;
    UserType currentUserType;
    Guest guest;
    User user;
    Teacher teacher;
    Student student;

    void displayCourses();
    void displayTeachers();
    void displaySubcatalogs();
    void registerUser();
    void authorizeUser();
    void UserProfile();
    void ChangeProfileInfo(int choice);

    // Меню для различных типов пользователей
    void displayMenuGuest();
    void displayMenuUser();
    void displayMenuStudent();
    void displayMenuTeacher();

    // Обработка ввода для различных типов пользователей
    void handleGuestInput();
    void handleUserInput();
    void handleStudentInput();
    void handleTeacherInput();
public:
    Interface();
    virtual ~Interface();
    void displayMenu();
};
