//

#include <utility>

#include "../../../include/teacher.h"

Teacher::Teacher()= default;

Teacher::~Teacher() = default;

Teacher::Teacher(int _id, std::map<int, User> users) : User(_id, users){     //Use User constructor
    data_t.id = _id;
}

Teacher::Teacher(const User_data &userData, Teacher_data teacherData)
        : User(userData), data_t(std::move(teacherData)) {

}

void Teacher::get_lesson_request(std::string student_id, std::string course_name, double lesson_price) {

}

void Teacher::set_data(const Teacher_data &data_) {
    Teacher::data_t = data_;
}

void Teacher::set_id(int id) {
    data_t.id = id;
}

void Teacher::set_courses(std::map<std::string, std::vector<std::string>> courses) {
    data_t.studentSchedules = courses;
}

void Teacher::set_exp(int exp) {
    data_t.experience = exp;
}

void Teacher::set_rate(double rating) {
    data_t.rating = rating;
}

const Teacher_data &Teacher::get_tdata() const{
    return data_t;
}

int &Teacher::get_id() {
    return data_t.id;
}

std::map<std::string, std::vector<std::string>> &Teacher::get_courses() {
    return data_t.studentSchedules;
}

int &Teacher::get_exp() {
    return data_t.experience;
}

double &Teacher::get_rate() {
    return data_t.rating;
}