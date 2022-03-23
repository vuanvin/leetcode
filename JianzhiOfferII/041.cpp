#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
private:
    vector<int> arr;
    long sum;
    int ptr;
    int size;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->ptr = 0;
        this->sum = 0;
    }
    
    double next(int val) {
        if (arr.size() < size) {
            arr.push_back(val);
            sum += val;
            return sum * 1.0 / arr.size();
        } else {
            sum -= arr[ptr];
            arr[ptr] = val;
            sum += val;
            ptr = (ptr + 1) % size;

            return sum * 1.0 / size;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */