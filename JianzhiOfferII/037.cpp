#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> St;
        St.reserve(n);
        vector<int> ans;
        ans.reserve(n);

        for (auto aster : asteroids) {
            if (St.empty()) {
                if (aster > 0) { St.push_back(aster); }
                else { ans.push_back(aster); }
            } else {
                int old_aster = St.back();
                if (aster > 0) {
                    St.push_back(aster);
                } else {
                    while (old_aster <= -aster) {
                        St.pop_back();
                        if (old_aster == -aster) { break; }

                        if (St.empty()) {
                            ans.push_back(aster);
                            break;
                        }
                        old_aster = St.back();
                    }
                }
            }
        }
        ans.insert(ans.end(), St.begin(), St.end());
        return ans;
    }
};