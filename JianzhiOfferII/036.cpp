#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans;
        stack<int> nums;
        for (auto token : tokens) {
            if (token == "+") {
                auto val1 = nums.top();
                nums.pop();
                auto val2 = nums.top();
                nums.pop();
                nums.push(val2 + val1);
            } else if (token == "*") {
                auto val1 = nums.top();
                nums.pop();
                auto val2 = nums.top();
                nums.pop();
                nums.push(val2 * val1);
            } else if (token == "/") {
                auto val1 = nums.top();
                nums.pop();
                auto val2 = nums.top();
                nums.pop();
                nums.push(val2 / val1);
            } else if (token == "-") {
                auto val1 = nums.top();
                nums.pop();
                auto val2 = nums.top();
                nums.pop();
                nums.push(val2 - val1);
            } else {
                nums.push(stoi(token));
            }
        }

        return nums.top();
    }
};