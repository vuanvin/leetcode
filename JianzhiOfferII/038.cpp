#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            auto a = temperatures[i];
            while (!st.empty()) {
                auto j = st.top();
                auto b = temperatures[j];
                if (a < b) {
                    ans[i] = j - i;
                    break;
                }
                st.pop();
            }

            st.push(i);
        }
        return ans;
    }
};