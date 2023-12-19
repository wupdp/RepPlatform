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

void Student::send_lesson_request(int teacher_id, string course_name, map<int, Teacher> teachers) {
    if (current_card.getBalance() >= 30) {
        teachers[teacher_id].get_lesson_request(get_id(), course_name);
        current_card.add_balance(-30);
    }
    else
        cout << "Недостаточно средтв на балансе";
}

const StudentData &Student::getData() const {
    return data_s;
}

const SCHEDULE &Student::get_lessons() const {
    return data_s.courseSchedules;
}

void Student::setData(const StudentData &data_) {
    Student::data_s = data_;
}

void Student::set_id(const int id) {
    data_s.id = id;
}

void Student::set_lessons(const SCHEDULE lessons) {
    data_s.courseSchedules = lessons;
}

void Student::sent_notif(string course, int t_id, string date) {
    data_s.courseSchedules[course][t_id].push_back(date);

    string notification = "Установлено занятие на " + date + " по курсу " + course;
    data.notifications.push_back(notification);
}



Student::~Student() = default;
