//

#include "../../../include/User.h"
#include "../../../include/student.h"

//
// Created by wupdp on 07.11.23.
Student::Student() {

}

Student::Student(int id, std::map<int, User> users) : User(id, users) {
}


Student::Student(User_data userData, StudentData studentData) {
    this->data_s = studentData;
    this->set_data(userData);
}

void Student::view_messages() {

}

void Student::send_lesson_request(std::string teacher_id, std::string course_name, double lesson_price) {

}

const StudentData &Student::getData() const {
    return data_s;
}

const std::map<std::string, std::vector<std::string>> &Student::get_lessons() const {
    return data_s.courseSchedules;
}

void Student::setData(const StudentData &data_) {
    Student::data_s = data_;
}

void Student::set_id(const int id) {
    data_s.id = id;
}

void Student::set_lessons(const std::map<std::string, std::vector<std::string>> lessons) {
    data_s.courseSchedules = lessons;
}


Student::~Student() = default;
