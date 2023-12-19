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
    UserType current_user_type;
    Guest guest;
    User user;
    Teacher teacher;
    Student student;

    void display_courses();
    void display_teachers();
    void display_subcatalogs();
    void register_user();
    void authorize_user();
    void teacher_profile();
    void user_profile();
    void change_profile(int choice);
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
    //Работа с памятью
    void update_files();
    void get_data();
    void clear();
public:
    Interface();

    virtual ~Interface();
    void displayMenu();
};