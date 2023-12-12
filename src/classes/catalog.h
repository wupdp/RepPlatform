//
// Created by wupdp on 12.12.23.
//

#ifndef REPPLATFORM_CATALOG_H
#define REPPLATFORM_CATALOG_H
#include "subcatalog.h"

class Catalog {
    std::vector<Subcatalog> subcatalogs;

public:
    Catalog();
    ~Catalog();

    // Методы для работы с каталогом и подкаталогами
    void addSubcatalog(const Subcatalog &subcatalog);
    static int find_course(std::string name);
    static std::vector<std::string> list_catalog();
    // Другие методы для работы с подкаталогами
};


#endif //REPPLATFORM_CATALOG_H
