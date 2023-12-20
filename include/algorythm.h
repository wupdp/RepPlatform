#ifndef REPPLATFORM_ALGORYTHM_H
#define REPPLATFORM_ALGORYTHM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "stack.h"
#include <string>
#include "user.h"
#include "teacher.h"
#include "student.h"
#include "courses.h"
#include "subcatalog.h"
#include "catalog.h"
#include "cards.h"

class Algorithm {
public:
    static void parse_courses(Catalog& catalog);
    static void parse_users(map<int, User>& usersMap);
    static void parse_teachers(map<int, Teacher>& teachersMap, map<int, User>& usersMap);
    static void parse_students(map<int, Student> &studentsMap, map<int, User> &usersMap);
    static void parse_cards(int idToFind, Cards& cardsObj);
    static void parse_schedule_students(SCHEDULE, Stack<int>&);
    static void parse_schedule_courses(SCHEDULE schedule, Stack<string> &courses);
    static void write_cards(const Cards &cardsObj);
    static void write_students(const map<int, Student> &studentsMap);
    static void write_teachers(const map<int, Teacher>& teachersMap);
    static void write_users(const map<int, User> &usersMap);
    static void write_courses(Catalog &catalog);
};

#endif //REPPLATFORM_ALGORYTHM_H
