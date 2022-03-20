#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;

        function<void(string, int, int)> Find;

        Find = [&](string addr, int p, int ord) {
            if (p == n and ord == 4) {
                res.push_back(addr);
            } else if (p == n or ord == 4) {
                return;
            } else {
                if (ord > 0) { addr += "."; }

                Find(addr + s[p], p + 1, ord + 1);

                if (p < n - 1 and s[p] != '0')
                    Find(addr + s.substr(p, 2), p + 2, ord + 1);

                if (p < n - 2 and s[p] != '0' and stoi(s.substr(p, 3)) <= 255)
                    Find(addr + s.substr(p, 3), p + 3, ord + 1);
            }

        };

        Find(string(), 0, 0);
        return res;
    }
};