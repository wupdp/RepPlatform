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
    currentUserType = GUEST;
}

//
// Created by wupdp on 17.12.23.

void Interface::displayMenuGuest() {
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

void Interface::displayMenu() {
    system("clear");

    switch (currentUserType) {
        case GUEST:
            handleGuestInput();
            break;
        case USER:
            handleUserInput();
            break;
        case STUDENT:
            handleStudentInput();
            break;
        case TEACHER:
            handleTeacherInput();
            break;
        default:
            std::cout << "Неправильный тип пользователя." << std::endl;
            break;
    }
}


void Interface::handleGuestInput() {
    int choice;
    while (true) {
        displayMenuGuest();
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
            case 5:
                registerUser();
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

void Interface::registerUser() {
    User_data userData; // Создаем структуру для данных нового пользователя

    std::cout << "Введите имя пользователя: ";
    std::cin >> userData.username;

    std::cout << "Введите пароль: ";
    std::cin >> userData.password;

    std::cout << "Введите номер телефона: ";
    std::cin >> userData.phoneNumber;

    //TODO Card
    //TODO add id

    int userId = guest.register_user(userData, usersMap); // Регистрация пользователя

    if (userId != -1) {
        // Регистрация прошла успешно, можно выполнить дополнительные действия, если нужно
        currentUserType = USER;
        std::cout << "Регистрация прошла успешно. Теперь вы зарегистрированный пользователь." << std::endl;
    } else {
        // Регистрация не удалась из-за уже существующего имени пользователя
        std::cout << "Ошибка регистрации. Пользователь с таким именем уже существует." << std::endl;
    }
}


Interface::~Interface() {

}

void Interface::displayMenuUser() {

}

void Interface::displayMenuStudent() {

}

void Interface::displayMenuTeacher() {

}

void Interface::handleUserInput() {

}

void Interface::handleStudentInput() {

}

void Interface::handleTeacherInput() {

}
