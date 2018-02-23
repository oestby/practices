#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <algorithm>

class Dummy
{
public:
    int *num;
    Dummy()
    {
        num = new int(0);
    }
    Dummy(const Dummy &d)
    {
        num = new int(*d.num);
    }

    ~Dummy()
    {
        delete num;
    }

    Dummy operator=(Dummy rhs)
    {
        std::swap(num, rhs.num);
        return *this;
    }
};

#endif
