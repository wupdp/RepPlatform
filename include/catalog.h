#ifndef REPPLATFORM_CATALOG_H
#define REPPLATFORM_CATALOG_H
#include "subcatalog.h"

class Catalog {
    map<string, Subcatalog> subcatalogs;

public:
    Catalog();
    ~Catalog();

    void add_subcatalog(const string& undercatalog_name);
    Course find_course(string name);
    bool has_subcatalog(const string& subcatalog) const;
    Subcatalog& get_subcatalog(const string& subcatalogName);
    map<string, Subcatalog> get_subcatalogs();
    void display_courses();
    void clear();
    friend ostream& operator<<(ostream& os, const Catalog& catalog);
};

#endif //REPPLATFORM_CATALOG_H