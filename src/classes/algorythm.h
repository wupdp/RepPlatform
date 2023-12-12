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
    void parse_users();
    void parse_teachers();
    void parse_students();
    void parse_cards();
};


#endif //REPPLATFORM_ALGORYTHM_H
