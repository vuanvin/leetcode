#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;
        sum /= 2;

        unordered_set<int> S;
        S.insert(0);

        for (auto num : nums) {
            unordered_set<int> SS;
            for (auto x : S) {
                if (x + num <= sum)
                    SS.insert(x + num);
            }
            S.insert(SS.begin(), SS.end());
            if (S.count(sum)) return true;
        }
        return false;
    }
};