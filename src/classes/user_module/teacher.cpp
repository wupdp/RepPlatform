//

#include <utility>

#include "../../../include/teacher.h"

Teacher::Teacher()= default;

Teacher::~Teacher() = default;

Teacher::Teacher(int _id) {     //Use User constructor
    data.id = _id;
}

Teacher::Teacher(const User_data &userData, Teacher_data teacherData)
        : User(userData), data(std::move(teacherData)) {

}

void Teacher::get_lesson_request(std::string student_id, std::string course_name, double lesson_price) {

}

void Teacher::set_data(const Teacher_data &data_) {
    Teacher::data = data_;
}

void Teacher::set_id(int id) {
    data.id = id;
}

void Teacher::set_courses(std::map<std::string, std::vector<std::string>> courses) {
    data.studentSchedules = courses;
}

void Teacher::set_exp(int exp) {
    data.experience = exp;
}

void Teacher::set_rate(double rating) {
    data.rating = rating;
}

Teacher_data &Teacher::get_data() {
    return data;
}

int &Teacher::get_id() {
    return data.id;
}

std::map<std::string, std::vector<std::string>> &Teacher::get_courses() {
    return data.studentSchedules;
}

int &Teacher::get_exp() {
    return data.experience;
}

double &Teacher::get_rate() {
    return data.rating;
}