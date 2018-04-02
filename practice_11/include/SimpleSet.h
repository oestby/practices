#ifndef SIMPLESET_HPP
#define SIMPLESET_HPP
#include <stdexcept>

template<class T>
class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet(int size = 0):
        currentSize(size), maxSize(512) 
        {
            data = new T[maxSize];
        }
        /** Destructor */
        ~SimpleSet() {
            delete[] data;
        }

        /** Insert i into set, return true if the element was inserted, else false **/
        bool insert(T i) {
            if (find(i) >= 0) return false;
            else {
                resize(1);
                data[currentSize - 1] = i;
                return true;
            }
        }
        /** Returns true if i is in the set **/
        bool exists(T i) {
            if (find(i) >= 0) {
                return true;
            }
            else {
                return false;
            }
        }
        /** Removes i from the set, return true if an element was removed **/
        bool erase(T i) {
            int index = find(i);
            if(index >= 0) {
                for (int i = index; i < currentSize - 1; i++) {
                    data[i] = data[i + 1];
                }
                resize(-1);
                return true;
            }
            return false;
        }
        int getLength() const {
            return currentSize;
        }

        T at(int index) {
            if(index < 0 || index > currentSize) {
                throw std::out_of_range("ERROR - Index out of range");
            }
            else {
                return data[index];
            }
        }
        
        int getLength(void) const {
            return currentSize;
        }


        T* begin() {
            return &data[0];
        }

        T* end() {
            return &data[currentSize];
        }

    private:
        /** Dynamic array containing set elements **/
        T *data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
        int find(T i) {
            for (int j = 0; j < currentSize; j++) {
                if (data[j] == i) return j;
            }
            return -1;
        }
        /** Resizes data, superflous elements are dropped. **/
        void resize(int n) {
            if (n > 0) {
                if (currentSize != maxSize) {
                    currentSize++;
                }
            }
            else if(n < 0) {
                if (currentSize > 1) {
                    currentSize--;
                }
            }
        }
        

};

#endif

