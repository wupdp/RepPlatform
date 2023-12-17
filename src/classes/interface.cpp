//
// Created by wupdp on 17.12.23.
//
#include "../../include/interface.h"

Interface::Interface() {
    Algorithm::parse_courses(catalog);
    Algorithm::parse_users(usersMap);
    Algorithm::parse_students(studentsMap, usersMap);
    Algorithm::parse_teachers(teachersMap, usersMap);
}

void Interface::displayMenu() {
    {
        system("clear");
        std::cout << "=== Репетиционное обучение ===" << std::endl;
        std::cout << "1. Просмотр курсов" << std::endl;
        std::cout << "2. Просмотр пользователей" << std::endl;
        std::cout << "3. Просмотр преподавателей" << std::endl;
        std::cout << "4. Просмотр студентов" << std::endl;
        std::cout << "5. Просмотр карточек" << std::endl;
        std::cout << "6. Выход" << std::endl;
        std::cout << "Выберите опцию: ";
    }
}

void Interface::handleUserInput() {
    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayCourses();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                displayTeachers();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                displayCards();
                break;
            case 6:
                std::cout << "Выход из программы." << std::endl;
                return;
            default:
                std::cout << "Неверный выбор. Пожалуйста, выберите снова." << std::endl;
                break;
        }
    }

}

void Interface::displayCourses() {

}

void Interface::displayUsers() {

}

void Interface::displayTeachers() {

}

void Interface::displayStudents() {

}

void Interface::displayCards() {

}

Interface::~Interface() {

}
