//
// Created by wupdp on 25.11.23.
//

#include "../../include/algorythm.h"

using namespace std;

void Algorithm::parse_cards(int idToFind, Cards &cardsObj) {
    ifstream file("../var/info/Cards");
    string line;
    while (getline(file, line)) {
        int id;
        string number, validity, cvcCodeStr, holderName;

        istringstream iss(line);
        getline(iss, cvcCodeStr, '/');
        getline(iss, number, '/');
        getline(iss, validity, '/');
        string cvcStr;
        getline(iss, cvcStr, '/');
        getline(iss, holderName);

        istringstream cvcStream(cvcStr);
        int cvcCode;
        cvcStream >> cvcCode;

        istringstream idStream(cvcCodeStr);
        idStream >> id;

        if (id == idToFind) {
            cardsObj.setNumber(number);
            cardsObj.setValidity(validity);
            cardsObj.setCvcCode(cvcCode);
            cardsObj.setHolderName(holderName);

            cout << "Card found! ID: " << id << ", Number: " << number << ", Validity: " << validity << ", CVC: "
                      << cvcCode << endl;

            break;
        }
    }
    file.close();
}

void Algorithm::parse_students(map<int, Student> &studentsMap, map<int, User> &usersMap) {
    ifstream file("../var/info/Students");
    string line;

    while (getline(file, line)) {
        istringstream iss(line);

        string studentIdStr, coursesStr;
        getline(iss, studentIdStr, '/'); // Получение ID студента

        int studentId = stoi(studentIdStr);

        getline(iss, coursesStr); // Получение данных о курсах и расписании

        // Разделение данных coursesStr на отдельные курсы и их расписание
        istringstream coursesStream(coursesStr);
        string courseInfo;
        map<string, vector<string>> courseSchedules;

        while (getline(coursesStream, courseInfo, '}')) {
            istringstream courseStream(courseInfo);

            string courseName;
            vector<string> schedule;

            // Извлечение имени курса
            getline(courseStream, courseName, '{');

            // Извлечение расписания занятий для этого курса
            string scheduleInfo;
            getline(courseStream, scheduleInfo);

            istringstream scheduleStream(scheduleInfo);
            string lessonInfo;
            while (getline(scheduleStream, lessonInfo, '/')) {
                schedule.push_back(lessonInfo);
            }

            courseSchedules[courseName] = schedule;
        }

        // Создание объекта StudentData с извлеченными данными
        StudentData studentData{
                studentId,
                courseSchedules
        };

        // Получение данных пользователя из usersMap
        User_data userData = usersMap[studentId].get_data();

        // Создание объекта Student и заполнение его данными
        Student newStudent(userData, studentData);

        parse_cards(newStudent.get_wallet_id(), newStudent.current_card);
        // Добавление объекта Student в studentsMap
        studentsMap[studentId] = newStudent;
    }

    file.close();
}


void Algorithm::parse_teachers(map<int, Teacher>& teachersMap, map<int, User>& usersMap) {
    ifstream file("../var/info/Teachers");
    string line;

    while (getline(file, line)) {
        istringstream iss(line);

        string teacherIdStr, coursesStr, experienceStr, ratingStr;
        getline(iss, teacherIdStr, '/'); // Получение ID учителя

        int teacherId = stoi(teacherIdStr);

        getline(iss, coursesStr, '/'); // Получение данных о курсах и расписании
        getline(iss, experienceStr, '/'); // Получение стажа
        getline(iss, ratingStr); // Получение рейтинга

        map<string, vector<string>> studentSchedules;

        // Разделение данных coursesStr на отдельные курсы и их расписание
        istringstream coursesStream(coursesStr);
        string courseInfo;
        while (getline(coursesStream, courseInfo, '}')) {
            istringstream courseStream(courseInfo);

            string courseName;
            getline(courseStream, courseName, '{');

            string studentInfo;
            while (getline(courseStream, studentInfo, '}')) {
                istringstream studentStream(studentInfo);

                string studentIdStr, scheduleStr;
                getline(studentStream, studentIdStr, ':');
                int studentId = stoi(studentIdStr);

                getline(studentStream, scheduleStr);
                istringstream scheduleStream(scheduleStr);

                string date;
                vector<string> scheduleDates;
                while (getline(scheduleStream, date, ' ')) {
                    scheduleDates.push_back(date);
                }

                studentSchedules[to_string(studentId)] = scheduleDates;
            }
        }

        // Получение данных пользователя из usersMap
        User_data userData = usersMap[teacherId].get_data();

        // Создание объекта TeacherData с извлеченными данными
        Teacher_data teacherData{
                teacherId,
                studentSchedules,
                stoi(experienceStr),
                stod(ratingStr)
        };

        // Создание объекта Teacher и заполнение его данными
        Teacher newTeacher(userData, teacherData);

        parse_cards(newTeacher.get_wallet_id(), newTeacher.current_card);
        // Добавление объекта Teacher в teachersMap
        teachersMap[teacherId] = newTeacher;
    }

    file.close();
}

void Algorithm::parse_users(map<int, User> &usersMap) {
    ifstream file("../var/info/Users");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string idStr, username, role, notificationsStr, walletStr, phoneNumber, password;

        getline(iss, idStr, '/');
        int id = stoi(idStr);

        getline(iss, username, '/');
        getline(iss, role, '/');
        getline(iss, notificationsStr, '/');
        getline(iss, walletStr, '/');
        int wallet = stoi(walletStr);
        getline(iss, phoneNumber, '/');
        getline(iss, password);

        vector<string> notifications;
        istringstream notificationsStream(notificationsStr);
        string notif;
        while (getline(notificationsStream, notif, ',')) {
            notifications.push_back(notif);
        }

        User_data user_data{username, id, role, notifications, wallet, phoneNumber, password};
        User newUser(user_data);
        parse_cards(newUser.get_wallet_id(), newUser.current_card);
        usersMap[id] = newUser;

        // Можно выполнить другие операции или вывод на консоль
    }
    file.close();
}

void Algorithm::parse_courses(Catalog &catalog) {
    ifstream file("../var/info/Courses");
    string line;
    while (getline(file, line)) {
        Course_struct course_data;

        istringstream iss(line);
        getline(iss, course_data.name, '/');
        getline(iss, course_data.subcatalog, '/');
        string teachersID;
        getline(iss, teachersID);

        istringstream teachersStream(teachersID);
        int teacherID;
        while (teachersStream >> teacherID) {
            course_data.teachers.push_back(teacherID);
            if (teachersStream.peek() == ',') {
                teachersStream.ignore();
            }
        }

        Course newCourse(course_data);

        if (!catalog.hasSubcatalog(course_data.subcatalog)) {
            catalog.addSubcatalog(course_data.subcatalog);
        }

        Subcatalog &subcatalog = catalog.getSubcatalog(course_data.subcatalog);
        subcatalog.add_course(course_data);
    }
    file.close();
}