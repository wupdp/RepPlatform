//
// Created by wupdp on 25.11.23.
//

#include "../../include/algorythm.h"

void Algorithm::parse_cards(int idToFind, Cards &cardsObj) {
    std::ifstream file("../var/info/Cards");
    std::string line;
    while (std::getline(file, line)) {
        int id;
        std::string number, validity, cvcCodeStr, holderName;

        std::istringstream iss(line);
        std::getline(iss, cvcCodeStr, '/');
        std::getline(iss, number, '/');
        std::getline(iss, validity, '/');
        std::string cvcStr;
        std::getline(iss, cvcStr, '/');
        std::getline(iss, holderName);

        std::istringstream cvcStream(cvcStr);
        int cvcCode;
        cvcStream >> cvcCode;

        std::istringstream idStream(cvcCodeStr);
        idStream >> id;

        if (id == idToFind) {
            cardsObj.setNumber(number);
            cardsObj.setValidity(validity);
            cardsObj.setCvcCode(cvcCode);
            cardsObj.setHolderName(holderName);

            std::cout << "Card found! ID: " << id << ", Number: " << number << ", Validity: " << validity << ", CVC: "
                      << cvcCode << std::endl;

            break;
        }
    }
    file.close();
}

void Algorithm::parse_students() {

}

void Algorithm::parse_teachers(std::map<int, Teacher>& teachersMap, std::map<int, User>& usersMap) {
    std::ifstream file("../var/info/Teachers");
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        std::string teacherIdStr, coursesStr, experienceStr, ratingStr;
        std::getline(iss, teacherIdStr, '/'); // Получение ID учителя

        int teacherId = std::stoi(teacherIdStr);

        std::getline(iss, coursesStr, '/'); // Получение данных о курсах и расписании
        std::getline(iss, experienceStr, '/'); // Получение стажа
        std::getline(iss, ratingStr); // Получение рейтинга

        std::map<std::string, std::vector<std::string>> studentSchedules;

        // Разделение данных coursesStr на отдельные курсы и их расписание
        std::istringstream coursesStream(coursesStr);
        std::string courseInfo;
        while (std::getline(coursesStream, courseInfo, '}')) {
            std::istringstream courseStream(courseInfo);

            std::string courseName;
            std::getline(courseStream, courseName, '{');

            std::string studentInfo;
            while (std::getline(courseStream, studentInfo, '}')) {
                std::istringstream studentStream(studentInfo);

                std::string studentIdStr, scheduleStr;
                std::getline(studentStream, studentIdStr, ':');
                int studentId = std::stoi(studentIdStr);

                std::getline(studentStream, scheduleStr);
                std::istringstream scheduleStream(scheduleStr);

                std::string date;
                std::vector<std::string> scheduleDates;
                while (std::getline(scheduleStream, date, ' ')) {
                    scheduleDates.push_back(date);
                }

                studentSchedules[std::to_string(studentId)] = scheduleDates;
            }
        }

        // Получение данных пользователя из usersMap
        User_data userData = usersMap[teacherId].get_data();

        // Создание объекта TeacherData с извлеченными данными
        Teacher_data teacherData{
                teacherId,
                studentSchedules,
                std::stoi(experienceStr),
                std::stod(ratingStr)
        };

        // Создание объекта Teacher и заполнение его данными
        Teacher newTeacher(userData, teacherData);

        // Добавление объекта Teacher в teachersMap
        teachersMap[teacherId] = newTeacher;
    }

    file.close();
}



void Algorithm::parse_users(std::map<int, User> &usersMap) {
    std::ifstream file("../var/info/Users");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, username, role, notificationsStr, walletStr, phoneNumber, password;

        std::getline(iss, idStr, '/');
        int id = std::stoi(idStr);

        std::getline(iss, username, '/');
        std::getline(iss, role, '/');
        std::getline(iss, notificationsStr, '/');
        std::getline(iss, walletStr, '/');
        int wallet = std::stoi(walletStr);
        std::getline(iss, phoneNumber, '/');
        std::getline(iss, password);

        std::vector<std::string> notifications;
        std::istringstream notificationsStream(notificationsStr);
        std::string notif;
        while (std::getline(notificationsStream, notif, ',')) {
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
    std::ifstream file("../var/info/Courses");
    std::string line;
    while (std::getline(file, line)) {
        Course_struct course_data;

        std::istringstream iss(line);
        std::getline(iss, course_data.name, '/');
        std::getline(iss, course_data.subcatalog, '/');
        std::string teachersID;
        std::getline(iss, teachersID);

        std::istringstream teachersStream(teachersID);
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