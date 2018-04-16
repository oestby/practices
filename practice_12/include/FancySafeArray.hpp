#ifndef FANCY_HPP
#define FANCY_HPP

#include <SafeArray.hpp>

template<class T>
class FancySafeArray: public SafeArray {
    public:
        FancySafeArray(size_t size): SafeArray(size) { };
    private:

};

#endif

