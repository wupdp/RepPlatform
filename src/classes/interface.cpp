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

void Interface::displayMenu() {
    system("clear");
    while (true) {
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
}

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


Interface::~Interface() {
    usersMap.clear();
    teachersMap.clear();
    studentsMap.clear();
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
            case 4:
                authorizeUser();
                return;
            case 5:
                registerUser();
                return;
            case 7:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                break;
        }
    }
}

void Interface::displayMenuUser() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Репетиционное обучение =====" << endl;
    cout << "================================" << endl;

    cout << "1. Просмотр всех курсов" << endl;
    cout << "2. Просмотр подкаталогов" << endl;
    cout << "3. Просмотр преподавателей" << endl;
    cout << "4. Ваши данные" << endl;
    cout << "5. Стать студентом" << endl;
    cout << "6. Стать преподавателем" << endl;
    cout << "7. Выйти из аккаунта" << endl;
    cout << "8. Удалить аккаунт" << endl;

    cout << "================================" << endl;
    cout << "9. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
}

void Interface::displayMenuStudent() {
    system("clear");
    cout << "================================" << endl;
    cout << "Студент: " << student.get_username() << endl; // Получите имя текущего студента
    cout << "================================" << endl;

    cout << "1. Просмотр расписания" << endl;
    cout << "2. Просмотр всех курсов" << endl;
    cout << "3. Просмотр подкаталогов" << endl;
    cout << "4. Просмотр сообщений" << endl;
    cout << "5. Просмотр преподавателей" << endl;
    cout << "6. Ваши данные" << endl;
    cout << "7. Отправить запрос на урок" << endl;
    cout << "8. Выйти из аккаунта" << endl;
    cout << "9. Удалить учетную запись студента" << endl;
    cout << "10. Удалить аккаунт" << endl;

    cout << "================================" << endl;
    cout << "11. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
}

void Interface::displayMenuTeacher() {

}

void Interface::handleUserInput() {
    int choice;
    while (true) {
        displayMenuUser();
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
            case 4:
                UserProfile();
                break;
            case 5: {
                user.register_as_student();
                studentsMap[user.get_id()] = Student(user.get_id(), usersMap); // Добавление студента в studentsMap по ID
                student = studentsMap[user.get_id()];
                currentUserType = STUDENT;
                return;
            }
            case 6: {
                user.register_as_teacher();
                teachersMap[user.get_id()] = Teacher(user.get_id(), usersMap); // Добавление преподавателя в teachersMap по ID
                teacher = teachersMap[user.get_id()];
                currentUserType = TEACHER;
                return;
            }
            case 7:
                currentUserType = GUEST;
                return;
            case 8:
                user.deactivate_account(usersMap);
                currentUserType = GUEST;
                return;
            case 9:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                break;
        }
    }
}

void Interface::handleStudentInput() {
    int choice;

    while (true) {
        displayMenuStudent();
        cin >> choice;

        switch (choice) {
            case 1:
                // Логика для просмотра расписания
                break;
            case 2:
                displayCourses();
                break;
            case 3:
                displaySubcatalogs();
                break;
            case 4:
                student.view_messages();
                break;
            case 5:
                displayTeachers();
                break;
            case 6:
                UserProfile();
                break;
            case 7: {
                string teacherId, courseName;
                double lessonPrice;

                cout << "Введите ID преподавателя: ";
                cin >> teacherId;

                cout << "Введите название курса: ";
                cin >> courseName;

                cout << "Введите стоимость урока: ";
                cin >> lessonPrice;

                student.send_lesson_request(teacherId, courseName, lessonPrice);
                break;
            }
            case 8:
                cout << "Выход из аккаунта." << endl;
                // Логика выхода из аккаунта студента
                exit(0);
            case 9:
                // Логика удаления учетной записи студента
                break;
            case 10:
                cout << "Удаление аккаунта." << endl;
                // Логика удаления аккаунта студента
                break;
            case 11:
                exit(0);
            default:
                cout << "Некорректный выбор." << endl;
                break;
        }
    }
}

void Interface::handleTeacherInput() {

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

    for (const auto &teacher_pair: teachersMap) {
        teacher = teacher_pair.second;
        const Teacher_data &teacherData = teacher.get_tdata();

        cout << "ID преподавателя: " << teacherData.id << endl;
        cout << "Имя преподавателя: " << teacher.get_username() << endl;
        cout << "Опыт работы: " << teacherData.experience << " лет" << endl;
        cout << "Рейтинг: " << teacherData.rating << endl;
        cout << endl;
    }
    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::displaySubcatalogs() {
    system("clear");

    cout << "================================" << endl;
    cout << "=== Просмотр подкаталогов =======" << endl;
    cout << "================================" << endl;

    map<string, Subcatalog> subcatalogs = catalog.getSubcatalogs();

    int index = 1;
    for (const auto &pair: subcatalogs) {
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
    system("clear");
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
        user = usersMap[userId];
        std::cout << "Регистрация прошла успешно. Теперь вы зарегистрированный пользователь." << std::endl;
    } else {
        // Регистрация не удалась из-за уже существующего имени пользователя
        std::cout << "Ошибка регистрации. Пользователь с таким именем уже существует." << std::endl;
    }
}


void Interface::authorizeUser() {
    system("clear");
    std::string username, password;

    std::cout << "Введите имя пользователя: ";
    std::cin >> username;

    std::cout << "Введите пароль: ";
    std::cin >> password;

    int userId = guest.authorize(username, password, usersMap); // Авторизация пользователя

    if (userId != -1) {
        // Авторизация прошла успешно, можно выполнить дополнительные действия, если нужно
        currentUserType = USER; // Установка текущего типа пользователя
        std::cout << "Авторизация прошла успешно. Добро пожаловать, " << username << "!" << std::endl;
    } else {
        // Неверные имя пользователя или пароль
        std::cout << "Ошибка авторизации. Проверьте имя пользователя и пароль." << std::endl;
    }
}

void Interface::UserProfile() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Профиль пользователя ======" << endl;
    cout << "================================" << endl;

    cout << "Имя пользователя: " << user.get_username() << endl;
    cout << "Ваша карта: " << user.current_card.getNumber() << endl;
    cout << "Баланс: " << user.current_card.getBalance() << endl;
    cout << "Номер телефона: " << user.get_phonenumber() << endl;
    cout << "Уведомления:" << endl;
    for (const auto &notification: user.get_notifications()) {
        cout << "- " << notification << endl;
    }

    cout << "================================" << endl;
    cout << "1. Изменить пароль" << endl;
    cout << "2. Изменить данные профиля" << endl;
    cout << "3. Пополнить баланс" << endl;
    cout << "4. Выход из профиля" << endl;
    cout << "Выберите действие: " << endl;

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (choice == 4)
        return;

    ChangeProfileInfo(choice);
}

void Interface::ChangeProfileInfo(int choice) {
    system("clear");
    switch (choice) {
        case 1: {
            string oldPassword;
            cout << "Введите старый пароль: ";
            cin >> oldPassword;
            if (user.check_password(oldPassword)) {
                string newPassword;
                cout << "Введите новый пароль: ";
                cin >> newPassword;
                user.change_password(newPassword);
                break;
            }
            cout << "Неверный пароль";
            break;
        }
        case 2: {
            while (true) {
                system("clear");
                cout << "================================" << endl;
                cout << "=== Изменение данных профиля ===" << endl;
                cout << "================================" << endl;
                cout << "1. Изменить имя пользователя" << endl;
                cout << "2. Изменить номер телефона" << endl;
                cout << "3. Изменить банковскую карту" << endl;
                cout << "4. Вернуться назад" << endl;

                int profileChoice;
                cin >> profileChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (profileChoice) {
                    case 1: {
                        string newUsername;
                        cout << "Введите новое имя пользователя: ";
                        cin >> newUsername;
                        user.set_username(newUsername);
                        break;
                    }
                    case 2: {
                        string newPhoneNumber;
                        cout << "Введите новый номер телефона: ";
                        cin >> newPhoneNumber;
                        user.change_phone_number(newPhoneNumber);
                        break;
                    }
                    case 3: {
                        string newCardNumber, newValidity, newHolderName;
                        int newCvcCode;

                        cout << "Введите новый номер карты: ";
                        cin >> newCardNumber;
                        user.current_card.setNumber(newCardNumber);

                        cout << "Введите новую дату действия: ";
                        cin >> newValidity;
                        user.current_card.setValidity(newValidity);

                        cout << "Введите новое имя держателя: ";
                        cin >> newHolderName;
                        user.current_card.setHolderName(newHolderName);

                        cout << "Введите новый CVC-код: ";
                        cin >> newCvcCode;
                        user.current_card.setCvcCode(newCvcCode);

                        break;
                    }

                    case 4:
                        break;
                    default:
                        cout << "Некорректный выбор." << endl;
                        break;
                }
                if (profileChoice == 4) {
                    break;
                }
            }
            break;
        }
        case 3:
            int num;
            cout << "Введите сумму, которая будет снята с вашей карты" << endl;
            cin >> num;
            user.current_card.add_balance(num);
        default:
            cout << "Некорректный выбор." << endl;
            break;
    }
}

