//
// Created by wupdp on 25.11.23.
//

#include "algorythm.h"

void Algorithm::parse_cards() {

}

void Algorithm::parse_students() {

}

void Algorithm::parse_teachers() {

}

void Algorithm::parse_users() {

}

void Algorithm::parse_courses(std::map<std::string, Course>& courses) {
    std::ifstream file("../var/info/Courses");
    std::string line;
    while (std::getline(file, line)) {
        Course_struct course_data;

        std::istringstream iss(line);
        std::getline(iss, course_data.name, '/');
        std::getline(iss, course_data.undercatalog, '/');
        std::getline(iss, course_data.catalog, '/');
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
        courses[course_data.name] = newCourse;
    }
    file.close();
}
