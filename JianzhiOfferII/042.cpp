#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    int slot;
    queue<int> time;
public:
    RecentCounter() {
        slot = 3000;
    }
    
    int ping(int t) {
        time.push(t);
        int early = t - slot;
        while (time.front() < early) {
            time.pop();
        }
        return time.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */