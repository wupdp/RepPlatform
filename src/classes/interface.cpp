//
// Created by wupdp on 17.12.23.
//

#include <iostream>
#include <limits>
#include "../../include/interface.h"

using namespace std;

Interface::Interface() {
    Algorithm::parse_courses(catalog);
    Algorithm::parse_users(usersMap);
    Algorithm::parse_students(studentsMap, usersMap);
    Algorithm::parse_teachers(teachersMap, usersMap);
}

void Interface::displayMenu() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Репетиционное обучение =====" << endl;
    cout << "================================" << endl;

    cout << "1. Просмотр всех курсов" << endl;
    cout << "2. Просмотр подкаталогов" << endl;
    cout << "3. Просмотр преподавателей" << endl;
    cout << "4. Авторизация" << endl;
    cout << "5. Регистрация" << endl;
    cout << "6. ..." << endl;

    cout << "================================" << endl;
    cout << "7. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
}

void Interface::handleUserInput() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayCourses();
                break;
            case 2:
                displaySubcatalogs();
                break;
            case 3:
                displayTeachers();
                break;
            case 7:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                break;
        }
    }
}

void Interface::displayCourses() {
    system("clear");

    cout << "========================================================================" << endl;
    cout << "========================       Список курсов      ======================" << endl;
    cout << "========================================================================" << endl;

    cout << catalog;

    cout << "================================" << endl;
    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}


void Interface::displayTeachers() {
    system("clear");
    if (teachersMap.empty()) {
        cout << "Нет зарегистрированных преподавателей." << endl;
        return;
    }

    for (const auto& teacher_pair : teachersMap) {
        const Teacher& teacher = teacher_pair.second;
        const Teacher_data& teacherData = teacher.get_tdata();

        cout << "ID преподавателя: " << teacherData.id << endl;
        cout << "Имя преподавателя: " << teacher.get_username() << endl;
        cout << "Опыт работы: " << teacherData.experience << " лет" << endl;
        cout << "Рейтинг: " << teacherData.rating << endl;
        cout << endl;
    }
    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::displaySubcatalogs() {
    system("clear");

    cout << "================================" << endl;
    cout << "=== Просмотр подкаталогов =======" << endl;
    cout << "================================" << endl;

    map<string, Subcatalog> subcatalogs = catalog.getSubcatalogs();

    int index = 1;
    for (const auto& pair : subcatalogs) {
        cout << index << ". " << pair.first << endl;
        ++index;
    }
    cout << "================================" << endl;
    cout << "Выберите номер подкаталога: ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice >= 1 && choice <= subcatalogs.size()) {
        auto it = subcatalogs.begin();
        advance(it, choice - 1);

        cout << "Выбранный подкаталог: " << it->first << endl;
        cout << "Курсы в подкаталоге " << it->first << ":" << endl;
        cout << it->second;
    } else {
        cout << "Некорректный выбор." << endl;
    }

    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

Interface::~Interface() {

}
