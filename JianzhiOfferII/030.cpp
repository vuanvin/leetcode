#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> num2loc;
    vector<int> loc2num;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (num2loc.count(val)) return false;
        int n = loc2num.size();

        num2loc[val] = n;
        loc2num.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!num2loc.count(val)) return false;

        int n = num2loc.size();
        auto loc = num2loc[val];
        num2loc.erase(val);

        if (n - 1 == loc) {
            loc2num.pop_back();
        } else {
            loc2num[loc] = loc2num[n-1];
            num2loc[loc2num[loc]] = loc;
            loc2num.pop_back();
        }
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int num = loc2num[rand() % loc2num.size()];
        return num;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */