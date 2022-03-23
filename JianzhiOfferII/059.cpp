#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> priQ;
    int size;

public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (auto num : nums) {
            if (priQ.size() < size) {
                priQ.push(num);
            } else {
                int val = priQ.top();
                if (num > val) {
                    priQ.pop();
                    priQ.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if (priQ.size() < size) {
            priQ.push(val);
        } else {
            auto num = priQ.top();
            if (val > num) {
                priQ.pop();
                priQ.push(val);
            }
        }

        return priQ.top();
    }
};