#include "coursecatalog.hpp"

#include <utility>
#include <fstream>

void
CourseCatalog::addCourse(std::string course, std::string course_code)
{
    courses[course_code] = course;
    //courses.insert(std::make_pair(course_code, course));

}

void
CourseCatalog::removeCourse(std::string course_code)
{
    auto search = courses.find(course_code);
    if (search != courses.end())
        courses.erase(search);
    else std::cout << "Nothing to remove." << std::endl;
}

std::string
CourseCatalog::getCourse(std::string course_code) const
{
    auto search = courses.find(course_code);
    if (search != courses.end())
    {
        return search->second;
    }
    else
    {
        return std::string("No match");
    }
}

std::map<std::string, std::string>::const_iterator CourseCatalog::cbegin(void) const
{
    return courses.cbegin();
}

std::map<std::string, std::string>::const_iterator CourseCatalog::cend(void) const
{
    return courses.cend();
}

CourseCatalog::CourseCatalog():
filename("default.txt")
{
    //empty
}

CourseCatalog::CourseCatalog(std::string filename):
filename(filename)
{
    std::string course, course_code;
    std::ifstream file(filename);
    while(getline(file, course_code, '\t'))
    {
        getline(file, course);
        this->addCourse(course, course_code);
    }

}

CourseCatalog::~CourseCatalog()
{
    std::ofstream file(filename);
    file << *this;
    file.close();
}

std::ostream&
operator<<(std::ostream& os, const CourseCatalog& cc)
{
    for (auto it = cc.cbegin(); it != cc.cend(); it++)
    {
        os << it->first << "\t" << it->second << std::endl;
    }
    return os;
}