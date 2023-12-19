#include <iostream>
#include "user.h"
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
    void teacherProfile();
    void UserProfile();
    void ChangeProfileInfo(int choice);
    void display_schedule_t();
    void display_schedule_s();
    void display_schedule_students();
    void display_schedule_courses(Teacher);
    void add_course();
    void delete_course();

    void display_lesson_requests();
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
    void update_files();
public:
    Interface();

    virtual ~Interface();
    void displayMenu();

    void get_data();
    void clear();
};
