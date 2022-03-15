#include <bits/stdc++.h>
using namespace std;

int maxProduct_1(vector<string>& words) {
    int n = words.size();
    int res = 0;
    vector<set<int>> map(26, set<int>());

    for (int i = 0; i < n; i++) {
        auto w = words[i];
        for (auto ch : w) {
            map[ch - 'a'].insert(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool non_sect = true;
            for (int k = 0; k < 26; k++) {
                if (map[k].count(i) && map[k].count(j)) {
                    non_sect = false;
                    break;
                }
            }

            if (non_sect) {
                int product = words[i].size() * words[j].size();
                res = max(res, product);
            }
        }
    }

    return res;
}

int maxProduct_2(vector<string>& words) {
    int n = words.size();
    int res = 0;
    vector<int> bitmap(n, 0);

    for (int i = 0; i < n; i++) {
        auto word = words[i];
        for (auto ch : word) {
            bitmap[i] |= 1 << (ch - 'a');
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(bitmap[i] & bitmap[j])) {
                int tmp = words[i].size() * words[j].size();
                res = max(res, tmp);
            }
        }
    }

    return res;
}

int maxProduct(vector<string>& words) {
    int n = words.size();
    int res = 0;
    unordered_map<int, int> bitMap;

    for (int i = 0; i < n; i++) {
        auto word = words[i];
        int mask = 0;
        for (auto ch : word) {
            mask |= 1 << (ch - 'a');
        }
        if (bitMap.count(mask)) {
            auto max_value = max(bitMap[mask], (int)word.size());
            bitMap[mask] = max_value;
        } else {
            bitMap[mask] = word.size();
        }
    }

    for (auto & x : bitMap) {
        for (auto & y : bitMap) {
            if (x.first & y.first == 0) {
                res = max(res, x.second * y.second);
            }
        }
    }

    return res;
}