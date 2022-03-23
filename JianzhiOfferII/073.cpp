#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0, mask = 0;

        int base = 1 << 30;
        for (int base = (1 << 30); base != 0; base >>= 1) {
            auto num = mask | base;

            int hour = 0;
            for (auto pile : piles) { 
                hour += (pile - 1 + num) / num;
                if (hour > h) break;
            }

            if (hour <= h) {
                ans = num;
            } else {
                mask |= base;
            }
        }

        return ans;
    }
};

class Solution_1 {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0, mask = 0;
        int maxn = 30;

        while (maxn) {

            for (int i = 0; i <= maxn; i++) {
                if (i == maxn) {
                    maxn = i - 1;
                    mask |= (1 << maxn);
                    break;
                }

                int hour = 0;
                auto num = mask | (1 << i);
                for (auto pile : piles) { 
                    hour += (pile - 1 + num) / num;
                    if (hour > h) break;
                }

                if (i == 0) {
                    if (hour <= h) {
                        ans = mask | 1;
                        maxn = 0;
                        break;
                    }
                    continue;
                }

                if (hour <= h) {
                    ans = mask | (1 << i);
                    mask |= (1 << (i - 1));
                    maxn = i;
                    break;
                }

                cout << maxn << endl;
            }
        }

        return ans;
    }
};