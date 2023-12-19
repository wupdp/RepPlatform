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
        string number, validity, idStr, holderName;

        istringstream iss(line);
        getline(iss, idStr, '/');
        getline(iss, number, '/');
        getline(iss, validity, '/');
        string cvcStr;
        getline(iss, cvcStr, '/');
        getline(iss, holderName);

        istringstream cvcStream(cvcStr);
        int cvcCode;
        cvcStream >> cvcCode;

        istringstream idStream(idStr);
        idStream >> id;

        if (id == idToFind) {
            cardsObj.setNumber(number);
            cardsObj.setValidity(validity);
            cardsObj.setCvcCode(cvcCode);
            cardsObj.setHolderName(holderName);

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
        SCHEDULE courseSchedules;
        istringstream coursesStream(coursesStr);
        string courseInfo;
        while (getline(coursesStream, courseInfo, '}')) {
            istringstream courseStream(courseInfo);

            string courseName;
            getline(courseStream, courseName, '{');

            string studentInfo;
            while (getline(courseStream, studentInfo, '}')) {
                istringstream studentStream(studentInfo);

                string teacherIdStr;
                getline(studentStream, studentIdStr, ':');
                int teacherId = stoi(studentIdStr);

                string scheduleStr;
                getline(studentStream, scheduleStr);
                istringstream scheduleStream(scheduleStr);

                string date;
                vector<string> scheduleDates;
                while (getline(scheduleStream, date, ' ')) {
                    scheduleDates.push_back(date);
                }

                courseSchedules[courseName][teacherId] = scheduleDates;
            }
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

        SCHEDULE studentSchedules;

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

                studentSchedules[courseName][studentId] = scheduleDates;
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

void Algorithm::parse_schedule_students(const map<string, map<int, vector<string>>> schedule, stack<int>& students_id) {
    for (const auto& course : schedule) {
        const map<int, vector<string>>& students_schedule = course.second;
        for (const auto& student_schedule : students_schedule) {
            const vector<string>& schedules = student_schedule.second;
            for (const string& date : schedules) {
                istringstream iss(date);
                string student_id_str;
                getline(iss, student_id_str, ':');
                int studentId = stoi(student_id_str);
                students_id.push(studentId);
            }
        }
    }
}


void Algorithm::parse_schedule_courses(const map<string, map<int, vector<string>>> schedule, stack<string>& courses) {
    for (const auto& course : schedule) {
        courses.push(course.first);
    }
}

void Algorithm::write_cards(const Cards &cardsObj) {
    ofstream file("../var/info/Cards", ios::app); // Открываем файл для добавления данных

    if (file.is_open()) {
        file << cardsObj.getId() << '/' << cardsObj.getNumber() << '/'
             << cardsObj.getValidity() << '/' << cardsObj.getCvcCode() << '/'
             << cardsObj.getHolderName() << '\n';

        file.close();
    } else {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void Algorithm::write_students(const map<int, Student>& studentsMap) {
    ofstream file("../var/info/Students");

    if (file.is_open()) {
        for (const auto& student : studentsMap) {
            const StudentData& studentData = student.second.getData();
            file << studentData.id << '/';

            const SCHEDULE& courseSchedules = studentData.courseSchedules;
            for (const auto& course : courseSchedules) {
                file << course.first << '{';

                for (const auto& teacher_schedule : course.second) {
                    file << teacher_schedule.first << ':';
                    for (const auto& date : teacher_schedule.second) {
                        file << date << ' ';
                    }
                }

                file << '}';
            }

            file << ' ';
        }

        file.close();
    } else {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void Algorithm::write_teachers(const map<int, Teacher>& teachersMap) {
    ofstream file("../var/info/Teachers");

    if (file.is_open()) {
        for (const auto& teacherData : teachersMap) {
            const Teacher& teacher = teacherData.second;

            file << teacher.get_id() << '/'; // Запись ID преподавателя

            const Teacher_data& teacherInfo = teacher.get_tdata();
            const SCHEDULE& studentSchedules = teacherInfo.studentSchedules;

            for (const auto& course : studentSchedules) {
                file << course.first << '{'; // Запись имени курса

                for (const auto& studentInfo : course.second) {
                    file << studentInfo.first << ':';

                    for (const auto& date : studentInfo.second) {
                        file << date << ' ';
                    }
                    file << '}';
                }
                file << '}';
            }
            file << '/' << teacherInfo.experience << '/' << teacherInfo.rating << '\n';
        }

        file.close();
    } else {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void Algorithm::write_users(const map<int, User>& usersMap) {
    ofstream file("../var/info/Users");

    if (file.is_open()) {
        for (const auto& userData : usersMap) {
            const User& user = userData.second;

            const User_data& userInfo = user.get_data();

            file << userInfo.id << '/';
            file << userInfo.username << '/';
            file << userInfo.role << '/';

            const vector<string>& notifications = userInfo.notifications;
            for (size_t i = 0; i < notifications.size(); ++i) {
                file << notifications[i];
                if (i != notifications.size() - 1) {
                    file << ',';
                }
            }

            file << '/' << userInfo.wallet << '/';
            file << userInfo.phoneNumber << '/';
            file << userInfo.password << '\n';
        }

        file.close();
    } else {
        cout << "Ошибка открытия файла!" << endl;
    }
}

void Algorithm::write_courses(Catalog& catalog) {
    ofstream file("../var/info/Courses");

    if (file.is_open()) {
        for (auto& subcatalog : catalog.getSubcatalogs()) {
            for (auto& course : subcatalog.second.get_courses()) {
                Course_struct courseData = course.second.getCurrentCourse();

                file << courseData.name << '/';
                file << courseData.subcatalog << '/';

                vector<int>& teachers = courseData.teachers;
                for (size_t i = 0; i < teachers.size(); ++i) {
                    file << teachers[i];
                    if (i != teachers.size() - 1) {
                        file << ',';
                    }
                }

                file << '\n';
            }
        }

        file.close();
    } else {
        cout << "Ошибка открытия файла!" << endl;
    }
}
