#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    string s;

    void dfs(int n, int sum) {
        if (n == 0 && sum == 0) {
            ans.push_back(s);
        } else if (n == 0) {
            return;
        } else {
            if (sum > 0) {
                s.push_back(')');
                dfs(n - 1, sum - 1);
                s.pop_back();
            }
            s.push_back('(');
            dfs(n - 1, sum + 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(2 * n, 0);
        return ans;
    }
};