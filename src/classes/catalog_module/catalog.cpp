#include "../../../include/catalog.h"

Catalog::Catalog() = default;

Catalog::~Catalog() = default;

void Catalog::add_subcatalog(const string& undercatalog_name) {
    if (subcatalogs.find(undercatalog_name) == subcatalogs.end()) {
        Subcatalog new_subcatalog(undercatalog_name);
        subcatalogs[undercatalog_name] = new_subcatalog;
    } else {
        cout << "Подкаталог " << undercatalog_name << " существует." << endl;
    }
}


Course Catalog::find_course(string name) {
    for (auto& subcatalog : subcatalogs) {
        Course course = subcatalog.second.find_course(name);
        if (!course.get_course_name().empty()) {
            return course;
        }
    }
    cout << "Error, course is not found\n";
    return Course();
}

ostream& operator<<(ostream& os, const Catalog& catalog) {
    for (const auto& subcatalog : catalog.subcatalogs) {
        os << subcatalog.second << endl;
    }
    return os;
}

bool Catalog::has_subcatalog(const string &subcatalog) const {
    return subcatalogs.find(subcatalog) != subcatalogs.end();
}

Subcatalog &Catalog::get_subcatalog(const string &subcatalogName) {
        return subcatalogs[subcatalogName];
}

void Catalog::display_courses() {
    if (subcatalogs.empty()) {
        cout << "Каталог курсов пуст." << endl;
        return;
    }

    for (const auto& pair : subcatalogs) {
        const Subcatalog& subcatalog = pair.second;
        cout << subcatalog;
    }
}

map<string, Subcatalog> Catalog::get_subcatalogs() {
    return subcatalogs;
}

void Catalog::clear() {
    for (auto &subcatalog: subcatalogs){
        subcatalog.second.clear();
    }
    subcatalogs.clear();
}