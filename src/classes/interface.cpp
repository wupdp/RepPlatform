//

#include <iostream>
#include <limits>
#include "../../include/interface.h"

using namespace std;

Interface::Interface() {
    get_data();
    currentUserType = GUEST;
}

void Interface::displayMenu() {
    system("clear");
    while (true) {
        update_files();
        get_data();
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
                cout << "Неправильный тип пользователя." << endl;
                break;
        }
    }
}

void Interface::displayMenuGuest() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Репетиционное обучение =====" << endl;
    cout << "====Гость=======================" << endl;
    cout << "================================" << endl;

    cout << "1. Просмотр всех курсов" << endl;
    cout << "2. Просмотр подкаталогов" << endl;
    cout << "3. Просмотр преподавателей" << endl;
    cout << "4. Авторизация" << endl;
    cout << "5. Регистрация" << endl;

    cout << "================================" << endl;
    cout << "0. Выход" << endl;
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            case 5:
                registerUser();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return;
            case 0:
                cout << "Выход из программы." << endl;
                update_files();
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}

void Interface::displayMenuUser() {
    system("clear");
    cout << "===================================" << endl;
    cout << "=== Репетиционное обучение ========" << endl;
    cout << "Пользователь:" << user.get_username() << endl;
    cout << "===================================" << endl;

    cout << "1. Просмотр всех курсов" << endl;
    cout << "2. Просмотр подкаталогов" << endl;
    cout << "3. Просмотр преподавателей" << endl;
    cout << "4. Ваши данные" << endl;
    cout << "5. Стать студентом" << endl;
    cout << "6. Стать преподавателем" << endl;
    cout << "7. Выйти из аккаунта" << endl;
    cout << "8. Удалить аккаунт" << endl;

    cout << "================================" << endl;
    cout << "0. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
}

void Interface::displayMenuStudent() {
    system("clear");
    cout << "===================================" << endl;
    cout << "=== Репетиционное обучение ========" << endl;
    cout << "Студент: " << student.get_username() << endl;
    cout << "===================================" << endl;

    cout << "1. Просмотр расписания" << endl;
    cout << "2. Просмотр всех курсов" << endl;
    cout << "3. Просмотр подкаталогов" << endl;
    cout << "4. Просмотр преподавателей" << endl;
    cout << "5. Ваши данные" << endl;
    cout << "6. Отправить запрос на урок" << endl;
    cout << "7. Выйти из аккаунта" << endl;
    cout << "8. Удалить учетную запись студента" << endl;
    cout << "9. Удалить аккаунт" << endl;

    cout << "================================" << endl;
    cout << "0. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
}

void Interface::displayMenuTeacher() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Меню преподавателя ========" << endl;
    cout << "===" << teacher.get_username() << endl;
    cout << "================================" << endl;
    cout << "1. Просмотр ваших курсов" << endl;
    cout << "2. Просмотр всех курсов" << endl;
    cout << "3. Просмотр подкаталогов" << endl;
    cout << "4. Просмотреть расписание" << endl;
    cout << "5. Ваши данные" << endl;
    cout << "6. Просмотреть студентов" << endl;
    cout << "7. Просмотреть запросы на уроки" << endl;
    cout << "8. Добавить свой курс" << endl;
    cout << "9. Удалить свой курс" << endl;
    cout << "10. Выйти из аккаунта" << endl;
    cout << "11. Удалить учетную запись преподавателя" << endl;
    cout << "12. Удалить аккаунт" << endl;
    cout << "================================" << endl;
    cout << "0. Выход" << endl;
    cout << "================================" << endl;
    cout << "Выберите опцию: ";
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
                system("clear");
                UserProfile();
                break;
            case 5: {
                if (user.get_role() != "S" && user.get_role() != "ST") {
                    studentsMap[user.get_id()] = Student(user.get_id(),usersMap); // Добавление студента в studentsMap по ID
                    if (user.get_role() == "T")
                        user.set_role("ST");
                    else
                        user.set_role("S");
                }
                student = studentsMap[user.get_id()];
                currentUserType = STUDENT;
                return;
            }
            case 6: {
                if (user.get_role() != "T" && user.get_role() != "ST") {
                    teachersMap[user.get_id()] = Teacher(user.get_id(),usersMap); // Добавление студента в studentsMap по ID
                    if (user.get_role() == "S")
                        user.set_role("ST");
                    else
                        user.set_role("T");
                }
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
            case 0:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                display_schedule_s();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                displayCourses();
                break;
            case 3:
                displaySubcatalogs();
                break;
            case 4:
                displayTeachers();
                break;
            case 5:
                system("clear");
                UserProfile();
                break;
            case 6: {
                int teacherId;
                double lessonPrice;

                cout << "Введите ID преподавателя: ";
                cin >> teacherId;

                // Вывод доступных курсов
                cout << "Доступные курсы: " << endl;
                Teacher teacher1(teacherId, usersMap);
                display_schedule_courses(teacher1);

                string selectedCourse;
                cout << "Выберите курс: ";
                cin >> selectedCourse;

                student.send_lesson_request(teacherId, selectedCourse, teachersMap);

                break;
            }

            case 7:
                cout << "Выход из аккаунта." << endl;
                currentUserType = GUEST;
                return;
            case 8:
                studentsMap.erase(student.get_id());
                student = Student();
                currentUserType = USER;
                return;
            case 9:
                cout << "Удаление аккаунта." << endl;
                studentsMap.erase(student.get_id());
                student = Student();
                user.deactivate_account(usersMap);
                currentUserType = GUEST;
                break;
            case 0:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Некорректный выбор." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    }
}

void Interface::handleTeacherInput() {
    int choice;

    while (true) {
        displayMenuTeacher();
        cin >> choice;

        switch (choice) {
            case 1:
                system("clear");
                display_schedule_courses(teacher);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                displayCourses();
                break;
            case 3:
                displaySubcatalogs();
                break;
            case 4:
                system("clear");
                display_schedule_t();
                break;
            case 5:
                teacherProfile();
                UserProfile();
                break;
            case 6:
                display_schedule_students();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 7:
                display_lesson_requests();
                break;
            case 8:
                add_course();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 9:
                delete_course();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 10:
                currentUserType = GUEST;
                return;
            case 11:
                currentUserType = GUEST;
                teachersMap.erase(teacher.get_id());
                teacher = Teacher();
                return;
            case 12:
                teacher.deactivate_account(usersMap);
                cout << "Удаление аккаунта." << endl;
                currentUserType = GUEST;
                return;
            case 0:
                cout << "Выход из программы." << endl;
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    for (const auto &teacher_pair: teachersMap) {
        teacher = teacher_pair.second;
        const Teacher_data &teacherData = teacher.get_tdata();

        cout << "ID преподавателя: " << teacherData.id << endl;
        cout << "Имя преподавателя: " << teacher.get_username() << endl;
        cout << "Опыт работы: " << teacherData.experience << " лет" << endl;
        cout << "Рейтинг: " << teacherData.rating << endl;
        cout << endl;
        display_schedule_courses(teacher);
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

    map<string, Subcatalog> subcatalogs = catalog.get_subcatalogs();

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

    cout << "Введите имя пользователя: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userData.username);

    cout << "Введите пароль: ";
    cin >> userData.password;

    cout << "Введите номер телефона: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userData.phone_number);

    int userId = guest.register_user(userData, usersMap); // Регистрация пользователя

    if (userId != -1) {
        // Регистрация прошла успешно, можно выполнить дополнительные действия, если нужно
        currentUserType = USER;
        user = usersMap[userId];
        cout << "Регистрация прошла успешно. Теперь вы зарегистрированный пользователь." << endl;
    } else {
        // Регистрация не удалась из-за уже существующего имени пользователя
        cout << "Ошибка регистрации. Пользователь с таким именем уже существует." << endl;
    }
}


void Interface::authorizeUser() {

    system("clear");
    string username, password;

    cout << "Введите имя пользователя: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, username);

    cout << "Введите пароль: ";
    cin >> password;

    int userId = guest.authorize(username, password, usersMap); // Авторизация пользователя

    if (userId != -1) {
        user = User(userId, usersMap);
        currentUserType = USER; // Установка текущего типа пользователя
        if (teachersMap.find(user.get_id()) != teachersMap.end()) {
            currentUserType = USER; // Установка текущего типа пользователя как преподаватель
            user.set_role("T");
            cout << "Авторизация прошла успешно, вы можете переключиться на преподавателя. Добро пожаловать, "
                 << username << "!" << endl;
        } else if (studentsMap.find(user.get_id()) != studentsMap.end()) {
            currentUserType = STUDENT; // Установка текущего типа пользователя как студент
            user.set_role("S");
            cout << "Авторизация прошла успешно, вы можете переключиться на студента. Добро пожаловать, " << username
                 << "!" << endl;
        } else {
            currentUserType = USER; // Установка текущего типа пользователя
            user.set_role("U");
            cout << "Авторизация прошла успешно. Добро пожаловать, " << username << "!" << endl;
        }
    } else {
        // Неверные имя пользователя или пароль
        cout << "Ошибка авторизации. Проверьте имя пользователя и пароль." << endl;
    }
}

void Interface::UserProfile() {
    cout << "================================" << endl;
    cout << "=== Профиль пользователя ======" << endl;
    cout << "================================" << endl;

    cout << "Имя пользователя: " << user.get_username() << endl;
    cout << "Ваша карта: " << user.current_card.get_number() << endl;
    cout << "Баланс: " << user.current_card.get_balance() << " byn" << endl;
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
    cout << "Выберите действие: ";

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
                        getline(cin, newPhoneNumber);
                        user.change_phone_number(newPhoneNumber);
                        break;
                    }
                    case 3: {
                        string newCardNumber, newValidity, newHolderName;
                        int newCvcCode;

                        cout << "Введите новый номер карты: ";
                        getline(cin, newCardNumber);
                        user.current_card.set_number(newCardNumber);

                        cout << "Введите новую дату действия: ";
                        cin >> newValidity;
                        user.current_card.set_validity(newValidity);

                        cout << "Введите новое имя держателя: ";
                        getline(cin, newHolderName);
                        user.current_card.set_HolderName(newHolderName);

                        cout << "Введите новый CVC-код: ";
                        cin >> newCvcCode;
                        user.current_card.set_cvc(newCvcCode);

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

void Interface::display_schedule_t() {
    const SCHEDULE &lessons = teacher.get_courses();

    cout << "================================" << endl;
    cout << "=== Расписание ========" << endl;
    cout << "================================" << endl;

    for (const auto &course: lessons) {
        cout << "Курс: " << course.first << endl;

        for (const auto &student_map: course.second) {
            cout << "  Студент: ";
            if (studentsMap.find(student_map.first) != studentsMap.end()) {
                cout << studentsMap.at(student_map.first).get_username() << endl;
            } else {
                cout << "Unknown Student" << endl;
            }

            cout << "  Расписание занятий:" << endl;

            for (const auto &date: student_map.second) {
                cout << "    " << date << endl;
            }
        }
        cout << endl;
    }

    cout << endl;
    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void Interface::display_schedule_courses(Teacher teacher_) {
    stack<string> courses_st;
    Algorithm::parse_schedule_courses(teacher_.get_courses(), courses_st);

    cout << "Список курсов:" << endl;
    while (!courses_st.empty()) {
        cout << courses_st.top() << endl;
        courses_st.pop();
    }
}

void Interface::display_schedule_students() {
    stack<int> students_st;
    Algorithm::parse_schedule_students(teacher.get_courses(), students_st);

    cout << "Ваши студенты:" << endl;
    while (!students_st.empty()) {
        int studentId = students_st.top();
        students_st.pop();

        if (studentsMap.find(studentId) != studentsMap.end()) {
            student = studentsMap[studentId];
            cout << "Имя: " << student.get_username() << endl;
        } else {
            cout << "Студент с ID " << studentId << " не найден" << endl;
        }
    }
}

void Interface::add_course() {
    string courseName;
    cout << "Введите название нового курса: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, courseName);

    bool found = false;
    string subcatalogName;

    // Поиск курса по всем подкаталогам
    for (auto &subcatalog: catalog.get_subcatalogs()) {
        if (subcatalog.second.find_course(courseName).get_course_name() == courseName) {
            found = true;
            subcatalogName = subcatalog.first;
            break;
        }
    }

    if (!found) {
        // Запрос имени подкаталога, если курс не найден
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Курс не найден. Введите имя подкаталога для нового курса: ";
        getline(cin, subcatalogName);

        // Проверка существования подкаталога и добавление курса в него
        if (!catalog.has_subcatalog(subcatalogName)) {
            catalog.add_subcatalog(subcatalogName);
        }

        Course_struct newCourseData;
        newCourseData.name = courseName;
        newCourseData.subcatalog = subcatalogName;

        // Добавление курса в подкаталог
        catalog.get_subcatalog(subcatalogName).add_course(newCourseData);
    }

    // Добавление курса в расписание преподавателя
    map<string, map<int, vector<string>>> &teacherCourses = teacher.get_courses();
    if (teacherCourses.find(courseName) == teacherCourses.end()) {
        teacherCourses[courseName] = map<int, vector<string>>();
    }
}


void Interface::delete_course() {
    string courseName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите название курса для удаления: ";
    getline(cin, courseName);

    // Удаление курса из расписания преподавателя
    map<string, map<int, vector<string>>> &teacherCourses = teacher.get_courses();
    auto it = teacherCourses.find(courseName);
    if (it != teacherCourses.end()) {
        teacherCourses.erase(it);
    }

    // Удаление айди преподавателя из объекта курса
    for (auto &subcatalog: catalog.get_subcatalogs()) {
        Course course = subcatalog.second.find_course(courseName);
        if (course.get_course_name() == courseName) {
            vector<int> teachers = course.get_course_teachers();
            auto teacherId = teacher.get_id();
            for (auto iter = teachers.begin(); iter != teachers.end(); ++iter) {
                if (*iter == teacherId) {
                    teachers.erase(iter);
                    break;
                }
            }
            course.set_teachers(teachers);
            break;
        }
    }
    cout << "Удаление завершено!";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::display_schedule_s() {
    SCHEDULE lessons = student.get_lessons();

    cout << "================================" << endl;
    cout << "=== Расписание ========" << endl;
    cout << "================================" << endl;

    for (const auto &course: lessons) {
        cout << "Курс: " << course.first << endl;

        for (const auto &teacher_map: course.second) {
            cout << "  Преподаватель: ";
            if (teachersMap.find(teacher_map.first) != teachersMap.end()) {
                cout << teachersMap.at(teacher_map.first).get_username() << endl;
            } else {
                cout << "Unknown Teacher" << endl;
            }

            cout << "  Расписание занятий:" << endl;

            for (const auto &date: teacher_map.second) {
                cout << "    " << date << endl;
            }
        }
        cout << endl;
    }

    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::display_lesson_requests() {
    SCHEDULE &lessons = teacher.get_courses();

    cout << "================================" << endl;
    cout << "=== Запросы на занятие ========" << endl;
    cout << "================================" << endl;

    for (auto &course : lessons) {
        cout << "Курс: " << course.first << endl;

        for (auto &student_map: course.second) {

            for (auto &date : student_map.second) {
                if (date.find("Request") != string::npos) {
                    cout << "    " << date << endl;
                    cout << "Установите дату занятия: ";
                    string newDate;
                    cin >> newDate;
                    date = newDate;
                    studentsMap[student_map.first].sent_notif(course.first, teacher.get_id(), newDate);
                }
            }

            cout << endl;
        }
    }

    cout << endl;
    cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Interface::teacherProfile() {
    system("clear");
    cout << "================================" << endl;
    cout << "=== Профиль преподавателя =====" << endl;
    cout << "================================" << endl;
    cout << "ID: " << teacher.get_id() << endl;
    cout << "Опыт: " << teacher.get_exp() << " лет" << endl;
    cout << "Рейтинг: " << teacher.get_rate() << endl;
}

void Interface::get_data() {
    clear();
    Algorithm::parse_courses(catalog);
    Algorithm::parse_users(usersMap);
    Algorithm::parse_students(studentsMap, usersMap);
    Algorithm::parse_teachers(teachersMap, usersMap);
}
void Interface::update_files() {
    usersMap[user.get_id()] = user;
    teachersMap[teacher.get_id()] = teacher;
    studentsMap[student.get_id()] = student;
    Algorithm::write_courses(catalog);
    Algorithm::write_students(studentsMap);
    Algorithm::write_teachers(teachersMap);
    Algorithm::write_users(usersMap);
}

void Interface::clear() {
    usersMap.clear();
    catalog.clear();
    studentsMap.clear();
    teachersMap.clear();
}