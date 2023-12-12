//
// Created by wupdp on 12.12.23.
//

#ifndef REPPLATFORM_CATALOG_H
#define REPPLATFORM_CATALOG_H
#include "subcatalog.h"

class Catalog {
    std::map<std::string, Subcatalog> subcatalogs;

public:
    Catalog();
    ~Catalog();

    void addSubcatalog(const Subcatalog &subcatalog);
    static int find_course(std::string name);
    static std::vector<std::string> list_catalog();
};


#endif //REPPLATFORM_CATALOG_H
