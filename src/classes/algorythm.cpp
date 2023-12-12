//
// Created by wupdp on 25.11.23.
//

#include "algorythm.h"

void Algorithm::parse_cards(int idToFind, Cards& cardsObj) {
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

            std::cout << "Card found! ID: " << id << ", Number: " << number << ", Validity: " << validity << ", CVC: " << cvcCode << std::endl;

            break;
        }
    }
    file.close();
}

void Algorithm::parse_students() {

}

void Algorithm::parse_teachers() {

}

void Algorithm::parse_users() {

}

void Algorithm::parse_courses(Catalog& catalog) {
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

        Subcatalog& subcatalog = catalog.getSubcatalog(course_data.subcatalog);
        subcatalog.add_course(course_data);
    }
    file.close();
}