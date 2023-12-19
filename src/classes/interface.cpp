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
                std::cout << "Неправильный тип пользователя." << endl;
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
                return;
            case 5:
                registerUser();
                return;
            case 0:
                cout << "Выход из программы." << endl;
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
    cout << "4. Просмотр сообщений" << endl;
    cout << "5. Просмотр преподавателей" << endl;
    cout << "6. Ваши данные" << endl;
    cout << "7. Отправить запрос на урок" << endl;
    cout << "8. Выйти из аккаунта" << endl;
    cout << "9. Удалить учетную запись студента" << endl;
    cout << "10. Удалить аккаунт" << endl;

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
    cout << "10. Отправить уведомление студентам" << endl;
    cout << "11. Выйти из аккаунта" << endl;
    cout << "12. Удалить учетную запись преподавателя" << endl;
    cout << "13. Удалить аккаунт" << endl;
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
                UserProfile();
                break;
            case 5: {
                user.register_as_student();
                studentsMap[user.get_id()] = Student(user.get_id(),
                                                     usersMap); // Добавление студента в studentsMap по ID
                student = studentsMap[user.get_id()];
                currentUserType = STUDENT;
                return;
            }
            case 6: {
                user.register_as_teacher();
                teachersMap[user.get_id()] = Teacher(user.get_id(),
                                                     usersMap); // Добавление преподавателя в teachersMap по ID
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
                // Логика для просмотра расписания TODO
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                displayCourses();
                break;
            case 3:
                displaySubcatalogs();
                break;
            case 4:
                student.view_messages(); //TODO
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 5:
                displayTeachers();
                break;
            case 6:
                //TODO
                UserProfile();
                break;
            case 7: {
                //TODO
                int teacherId;
                double lessonPrice;

                cout << "Введите ID преподавателя: ";
                cin >> teacherId;

                // Вывод доступных курсов
                cout << "Доступные курсы: " << endl;
                Teacher teacher1(teacherId, usersMap);
                displayCourses();

                int selectedCourseIndex;
                cout << "Выберите курс: ";
                cin >> selectedCourseIndex;

                break;
            }

            case 8:
                cout << "Выход из аккаунта." << endl;
                currentUserType = GUEST;
                return;
            case 9:
                studentsMap.erase(student.get_id());
                student = Student();
                currentUserType = USER;
                return;
            case 10:
                cout << "Удаление аккаунта." << endl;
                studentsMap.erase(student.get_id());
                student = Student();
                user.deactivate_account(usersMap);
                currentUserType = GUEST;
                break;
            case 11:
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
                display_schedule();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 5:
                UserProfile();
                break;
            case 6:
                display_schedule_students();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 7:
                // Логика для просмотра запросов на уроки
                break;
            case 8:
                add_course();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 9:
                delete_course();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            case 10:
                // Логика для отправки уведомления студентам
                break;
            case 11:
                currentUserType = GUEST;
                return;
            case 12:
                currentUserType = GUEST;
                teachersMap.erase(teacher.get_id());
                teacher = Teacher();
                return;
            case 13:
                teacher.deactivate_account(usersMap);
                cout << "Удаление аккаунта." << endl;
                currentUserType = GUEST;
                return;
            case 14:
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

    cout << "Введите имя пользователя: ";
    getline(cin, userData.username);

    cout << "Введите пароль: ";
    cin >> userData.password;

    cout << "Введите номер телефона: ";
    getline(std::cin, userData.phoneNumber);

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

    //TODO check teacher or student
    system("clear");
    std::string username, password;

    std::cout << "Введите имя пользователя: ";
    getline(cin, username);

    std::cout << "Введите пароль: ";
    std::cin >> password;

    int userId = guest.authorize(username, password, usersMap); // Авторизация пользователя

    if (userId != -1) {
        user = User(userId, usersMap);
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
    cout << "Баланс: " << user.current_card.getBalance() <<" byn" <<endl;
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
                        getline(cin, newPhoneNumber);
                        user.change_phone_number(newPhoneNumber);
                        break;
                    }
                    case 3: {
                        string newCardNumber, newValidity, newHolderName;
                        int newCvcCode;

                        cout << "Введите новый номер карты: ";
                        getline(cin, newCardNumber);
                        user.current_card.setNumber(newCardNumber);

                        cout << "Введите новую дату действия: ";
                        cin >> newValidity;
                        user.current_card.setValidity(newValidity);

                        cout << "Введите новое имя держателя: ";
                        getline(cin, newHolderName);
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

void Interface::display_schedule() {
    const std::map<std::string, std::map<int, std::vector<std::string>>>& schedule = teacher.get_courses();

    cout << "================================" << endl;
    cout << "=== Расписание ========" << endl;
    cout << "================================" << endl;

    for (const auto& course : schedule) {
        cout << "Курс: " << course.first << endl;
        cout << "Расписание: " << endl;

        for (const auto& student_schedule : course.second) {
            cout << "- ";
            int studentId = student_schedule.first;
            const std::vector<std::string>& dates = student_schedule.second;
            cout << "Студент ID: " << studentId << " - Расписание: ";
            for (const std::string& date : dates) {
                cout << date << " ";
            }
            cout << endl;
        }

        cout << endl;
        cout << "Нажмите Enter, чтобы вернуться в главное меню... ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
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
    std::string courseName;
    std::cout << "Введите название нового курса: ";
    getline(cin, courseName);

    bool found = false;
    std::string subcatalogName;

    // Поиск курса по всем подкаталогам
    for (auto& subcatalog : catalog.getSubcatalogs()) {
        if (subcatalog.second.find_course(courseName).get_course_name() == courseName) {
            found = true;
            subcatalogName = subcatalog.first;
            break;
        }
    }

    if (!found) {
        // Запрос имени подкаталога, если курс не найден
        std::cout << "Курс не найден. Введите имя подкаталога для нового курса: ";
        getline(cin, subcatalogName);

        // Проверка существования подкаталога и добавление курса в него
        if (!catalog.hasSubcatalog(subcatalogName)) {
            catalog.addSubcatalog(subcatalogName);
        }

        Course_struct newCourseData;
        newCourseData.name = courseName;
        newCourseData.subcatalog = subcatalogName;

        // Добавление курса в подкаталог
        catalog.getSubcatalog(subcatalogName).add_course(newCourseData);
    }

    // Добавление курса в расписание преподавателя
    std::map<std::string, std::map<int, std::vector<std::string>>>& teacherCourses = teacher.get_courses();
    if (teacherCourses.find(courseName) == teacherCourses.end()) {
        teacherCourses[courseName] = std::map<int, std::vector<std::string>>();
    }
}


void Interface::delete_course() {
    std::string courseName;
    std::cout << "Введите название курса для удаления: ";
    getline(cin, courseName);

    // Удаление курса из расписания преподавателя
    std::map<std::string, std::map<int, std::vector<std::string>>>& teacherCourses = teacher.get_courses();
    auto it = teacherCourses.find(courseName);
    if (it != teacherCourses.end()) {
        teacherCourses.erase(it);
    }

    // Удаление айди преподавателя из объекта курса
    for (auto& subcatalog : catalog.getSubcatalogs()) {
        Course course = subcatalog.second.find_course(courseName);
        if (course.get_course_name() == courseName) {
            std::vector<int> teachers = course.get_course_teachers();
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
    std::cout << "Удаление завершено!";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}