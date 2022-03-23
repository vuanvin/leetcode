#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> ord;
        int k = 0;
        for (auto n : arr2) {
            ord[n] = k++;
        }

        for (auto n : arr1) {
            if (!ord.count(n)) {
                ord[n] = INT_MAX;
            }
        }
        sort(arr1.begin(), arr1.end(), [&](int a, int b) { return ord[a] < ord[b] || (ord[a] == ord[b] && a < b); });

        return arr1;
    }
};