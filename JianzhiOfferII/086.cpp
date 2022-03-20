#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                f[i][i+k] = (s[i] == s[i+k] && (k <= 2 || f[i+1][i+k-1])) ? 1 : 0;
            }
        }

        vector<vector<string>> ans;
        vector<string> item;

        function<void(int)> Find;
        Find = [&] (int p) {
            if (p == n) {
                ans.push_back(item);
                return;
            }
            for (int i = p; i < n; i++) {
                if (f[p][i]) {
                    item.push_back(s.substr(p, i - p + 1));
                    Find(i + 1);
                    item.pop_back();
                }
            }
        };

        Find(0);
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    auto solu = Solution();
    solu.partition(s);
}