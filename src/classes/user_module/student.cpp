#include "../../../include/user.h"
#include "../../../include/student.h"
Student::Student() = default;

Student::Student(int id, map<int, User> users) : User(id, users) {
}


Student::Student(User_data userData, Student_data studentData) {
    this->data_s = studentData;
    this->set_data(userData);
}

void Student::send_lesson_request(int teacher_id, string course_name, map<int, Teacher>& teachers) {
    if (current_card.get_balance() >= 30) {
        teachers[teacher_id].get_lesson_request(get_id(), course_name);
        current_card.add_balance(-30);
    }
    else
        cout << "Недостаточно средтв на балансе";
}

const Student_data &Student::get_data_s() const {
    return data_s;
}

const SCHEDULE &Student::get_lessons() const {
    return data_s.Schedules;
}

void Student::set_data_s(const Student_data &data) {
    Student::data_s = data;
}

void Student::set_id(const int id) {
    data_s.id = id;
}

void Student::set_lessons(const SCHEDULE lessons) {
    data_s.Schedules = lessons;
}

void Student::sent_notif(string course, int t_id, string date) {
    data_s.Schedules[course][t_id].push_back(date);
    string notification = "Установлено занятие на " + date + " по курсу " + course;
    data.notifications.push_back(notification);
}

Student::~Student() = default;
