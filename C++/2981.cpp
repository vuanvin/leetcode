#include <leetcode.h>

class Solution {
public:
    int maximumLength(string s) {
        unordered_map<char, map<int, int>> umap;
        int n = s.size();
        char v = 0;
        int cnt = 0;
        for (auto u : s) {
            if (u == v) {
                cnt++;
            } else {
                umap[v][cnt]++;
                cnt = 1;
                v = u;
            }
        }
        umap[v][cnt]++;

        int ans = -1;
        for (auto item : umap) {
            auto & mp = item.second;
            auto st = mp.rbegin()->first;

            int acc = 0, acc_cnt = 0;
            for (int i = st; i > st - 3 && i > 0; i--) {
                int val = 0;

                if (mp.count(i)) {
                    val = mp[i];
                    acc_cnt += mp[i];
                }

                if (val + acc >= 3) {
                    ans = max(i, ans);
                    break;
                }
                acc += val;
                acc += acc_cnt;
            }
        }

        return ans;
    }
};