//
// Created by wupdp on 07.11.23.
//

#include "../../../include/teacher.h"

Teacher::Teacher()= default;

Teacher::~Teacher() = default;

Teacher::Teacher(int _id) {     //Use User constructor
    get_lessons();
    data.id = _id;
}


void Teacher::get_lesson_request(std::string student_id, std::string course_name, double lesson_price) {

}

void Teacher::view_lesson_schedule() {

}

void Teacher::edit_lesson_schedule() {

}

void Teacher::edit_profile() {

}

void Teacher::get_lessons() {

}

void Teacher::set_data(const TeacherData &data) {
    Teacher::data = data;
}

void Teacher::set_id(int id) {
    data.id = id;
}

void Teacher::set_courses(std::vector<std::pair<std::string, std::vector<std::string>>> courses) {
    data.courses = courses;
}

void Teacher::set_exp(int exp) {
    data.experience = exp;
}

void Teacher::set_rate(double rating) {
    data.rating = rating;
}

TeacherData Teacher::get_data() {
    return data;
}

int Teacher::get_id() {
    return data.id;
}

std::vector<std::pair<std::string, std::vector<std::string>>> Teacher::get_courses() {
    return data.courses;
}

int Teacher::get_exp() {
    return data.experience;
}

double Teacher::get_rate() {
    return data.rating;
}


