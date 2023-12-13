//
// Created by wupdp on 07.11.23.
//

#include "../../../include/User.h"
#include "../../../include/student.h"

Student::Student(int id) : User(id) {
    get_lessons();
}

void Student::view_messages() {

}

void Student::send_lesson_request(std::string teacher_id, std::string course_name, double lesson_price) {

}

void Student::view_lesson_schedule() {

}

void Student::get_lessons() {
    lesson_requests.emplace_back("PARSEd");
    lesson_schedule.emplace_back("Parsed");
}

Student::~Student() = default;
