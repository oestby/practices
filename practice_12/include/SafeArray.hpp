#ifndef SAFE_ARRAY_HPP
#define SAFE_ARRAY_HPP

#include <memory>
#include <iostream>
#include <exception>

template<class T>
class SafeArray {
    public:
        SafeArray(): size_(0) { }

        SafeArray(unsigned int size):
        size_(size)    
        {
            data = std::make_unique<T[]>(size_);
        }
        
        SafeArray(const SafeArray<T>& ar):
        size_(0)
        {
            size_ = ar.size();
            data.reset(new T[size_]);
            for(unsigned int i = 0; i < size_; ++i) {
                data[i] = ar[i];
            }
        }

        SafeArray<T>& operator=(const SafeArray<T>& ar) {
            size_ = ar.size();
            std::unique_ptr<T[]> temp = std::move(data);
            data.reset(new T[size_]);
            for(unsigned int i = 0; i < size_; ++i) {
                data[i] = ar[i];
            }
            return *this;
        }

        void insert(const T& value, size_t index) {
            if(size_ < index) throw 
            data[index] = value;
        }

        void resize(size_t new_size) {
            std::unique_ptr<T[]> temp(new T[new_size]{});
            for(size_t i = 0; i < new_size; ++i) {
                if(i >= size_) {
                    break;
                }
                temp[i] = data[i];
            }
            std::swap(temp, data);
            size_ = new_size;
        }

        T* begin(void) { return data.get(); }
        T* end(void) { return &data[size_]; };
        
        size_t size(void) const { return size_; }

        T& operator[](size_t index){
            if (index > size_) throw std::out_of_range;
            return data[index];
        }

        const T& operator[](size_t index) const {
            if (index > size_) throw std::out_of_range;
            return data[index];
        }
    
    private:
        unsigned int size_;
        std::unique_ptr<T[]> data;
};

#endif

