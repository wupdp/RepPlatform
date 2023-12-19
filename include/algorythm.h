//
// Created by wupdp on 25.11.23.
//

#ifndef REPPLATFORM_ALGORYTHM_H
#define REPPLATFORM_ALGORYTHM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include "User.h"
#include "teacher.h"
#include "student.h"
#include "courses.h"
#include "subcatalog.h"
#include "catalog.h"
#include "cards.h"

class Algorithm {
public:
    static void parse_courses(Catalog& catalog);
    static void parse_users(std::map<int, User>& usersMap);
    static void parse_teachers(std::map<int, Teacher>& teachersMap, std::map<int, User>& usersMap);
    static void parse_students(std::map<int, Student> &studentsMap, std::map<int, User> &usersMap);
    static void parse_cards(int idToFind, Cards& cardsObj);
    static void parse_schedule_students(std::map<std::string,std::map<int, std::vector<std::string>>>, std::stack<int>&);
    static void parse_schedule_courses(std::map<std::string,std::map<int, std::vector<std::string>>> schedule, std::stack<std::string> &courses);
};


#endif //REPPLATFORM_ALGORYTHM_H
