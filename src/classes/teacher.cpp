//
// Created by wupdp on 07.11.23.
//

#include "teacher.h"

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
    lesson_requests.emplace_back("PARSEd");
    lesson_schedule.emplace_back("Parsed");
}
