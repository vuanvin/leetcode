#include <leetcode.h>

class Iterator {
    struct Data;
    Data* data;

public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    int temp;
    int has_next;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        temp = Iterator::next();
    }
    int peek() { return temp; }
    int next() {
        int old = temp;
        if (Iterator::hasNext()) {
            temp = Iterator::next();
        } else {
            temp = 0;
        }
        return old;
    }
    bool hasNext() const { return temp != 0; }
};