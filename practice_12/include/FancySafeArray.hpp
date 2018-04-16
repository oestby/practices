#ifndef FANCY_HPP
#define FANCY_HPP

#include <iostream>
#include <SafeArray.hpp>

template<class T>
class FancySafeArray: public SafeArray {
    public:
        FancySafeArray(size_t size): SafeArray(size) { };
        FancySafeArray(const FancySafeArray<T>& ar): SafeArray(ar) { };

        FancySafeArray operator+(const FancySafeArray& rhs) const {
            size_t new_size = size_ + rhs.size;
            FancySafeArray new_array(new_size);
            for (size_t i = 0; i < size_; ++i) {
                new_array[i] = data[i];
            }
            for (size_t i = size_; i < rhs.size; ++i) {
                new_array[i] = rhs[i];
            }
            return new_array;
        }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const FancySafeArray& fsa) {
    os << "[";
    for (size_t i = 0; i < fsa.getSize(); ++i) {
        os << fsa[i];
        if(!i%5) os << std::endl;
    }
    os << "]" << std::endl;
    return os;
}

#endif
