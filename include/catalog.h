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

    void addSubcatalog(const std::string& undercatalog_name);
    Course find_course(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const Catalog& catalog);
    [[nodiscard]] bool hasSubcatalog(const std::string& subcatalog) const;
    Subcatalog& getSubcatalog(const std::string& subcatalogName);
};


#endif //REPPLATFORM_CATALOG_H
