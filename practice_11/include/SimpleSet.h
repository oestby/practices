#ifndef SIMPLESET_HPP
#define SIMPLESET_HPP

class SimpleSet{
    public:
        /** Construct empty set **/
        SimpleSet(int size = 0):
        currentSize(size), maxSize(512) 
        {
            data = new int[maxSize];
        }
        /** Destructor */
        ~SimpleSet() {
            delete[] data;
        }

        /** Insert i into set, return true if the element was inserted, else false **/
        bool insert(int i) {
            if (find(i) >= 0) return false;
            else {
                resize(1);
                data[currentSize - 1] = i;
                return true;
            }
        }
        /** Returns true if i is in the set **/
        bool exists(int i) {
            if (find(i) >= 0) {
                return true;
            }
            else {
                return false;
            }
        }
        /** Removes i from the set, return true if an element was removed **/
        bool erase(int i) {
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

        int* begin() {
            return &data[0];
        }

        int* end() {
            return &data[currentSize];
        }
        int at(int index) {
            if(index < 0 || index > currentSize) {
                exit(0);
            }
            else {
                return data[index];
            }
        }
        
        int getLength(void) const {
            return currentSize;
        }


    private:
        /** Dynamic array containing set elements **/
        int *data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
        int find(int i) {
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

