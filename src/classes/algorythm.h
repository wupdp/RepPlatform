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
    void parse_teachers();
    void parse_students();
    static void parse_cards(int idToFind, Cards& cardsObj);
};


#endif //REPPLATFORM_ALGORYTHM_H
