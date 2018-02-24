#ifndef CATALOG_HPP
#define CATALOG_HPP

#include <string>
#include <map>
#include <iostream>


class CourseCatalog
{
public:
    void addCourse(std::string course, std::string course_code);
    void removeCourse(std::string course_code);
    std::string getCourse(std::string course_code) const;
    std::map<std::string, std::string>::const_iterator cbegin(void) const;
    std::map<std::string, std::string>::const_iterator cend(void) const;

    CourseCatalog();
    CourseCatalog(std::string filename);
    ~CourseCatalog();

private:
    std::map<std::string, std::string> courses{};
    std::string filename;

};

std::ostream& operator<<(std::ostream& os, const CourseCatalog& cc);

#endif
