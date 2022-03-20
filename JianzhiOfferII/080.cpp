#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> sample;

        function<void(int, int)> Find;

        Find = [&] (int i, int ord) {
            if (ord == k) {
                ans.push_back(sample);
                return;
            } else if (i == n) {
                return;
            }

            Find(i + 1, ord);
            sample.push_back(i + 1);
            Find(i + 1, ord + 1);
            sample.pop_back();

        };

        Find(0, 0);

        return ans;
    }
};