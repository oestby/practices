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
            data.reset(new T[size_]);
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
            data.reset(new T[size_]);
            for(unsigned int i = 0; i < size_; ++i) {
                data[i] = ar[i];
            }
            //TODO Find out why this will not cast to a reference.
            return this;
        }

        void insert(const T& value, size_t index) {
            if(size_ < index) throw 
            data[index] = value;
        }

        void resize(size_t new_size) {
            std::unique_ptr<T[]> temp = std::move(data);
            data.reset(new T[new_size]);
            for (unsigned int i = 0; i < size_; i++) {
                data[i] = temp[i];
                if (i >= new_size) break;
            }
            size_ = new_size;
        }

        T* begin(void) { return data.get(); }
        T* end(void) { return &data[size_]; };
        
        size_t size(void) const { return size_; }

        T& operator[](size_t index){
            return data[index];
        }

        const T& operator[](size_t index) const {
            return data[index];
        }
    
    private:
        unsigned int size_;
        std::unique_ptr<T[]> data;
};

#endif

