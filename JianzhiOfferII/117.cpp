#include <bits/stdc++.h>
using namespace std;


int numSimilarGroups_1(vector<string>& strs) {
    int n = strs.size();
    vector<int> f(n, 1);
    vector<vector<int>> graph(n, vector<int>()); 

    char ss, st;
    for (int i = 0; i < n; i++) {
        auto s = strs[i];
        for (int j = i + 1; j < n; j++) {
            auto t = strs[j];
            if (s.size() != t.size()) continue;
            int x = 0;
            bool is = true;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] != t[k]) {
                    if (x == 2) {
                        is = false;
                        break;
                    }
                    if (x == 1) {
                        if (ss == t[k] && st == s[k]) {
                            is = true; 
                        } else {
                            is = false;
                            break;
                        }
                    } else {
                        ss = s[k];
                        st = t[k];
                        is = false;
                    }
                    x ++;
                }
            }
            if (is) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (f[i]) {
            res ++;
            f[i] = 0;
            stack<int> S;
            S.push(i);
            while (!S.empty()) {
                int p = S.top(); S.pop();
                for (auto q : graph[p]) {
                    if (f[q]) {
                        S.push(q);
                        f[q] = 0;
                    }
                }
            }
        }
    }

    return res;
}

int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();
    vector<int> f(n);
    int res = n;
    for (int i = 1; i < n; i++) f[i] = i;

    vector<vector<int>> graph(n, vector<int>()); 

    for (int i = 0; i < n; i++) {
        auto s = strs[i];
        for (int j = i + 1; j < n; j++) {
            auto t = strs[j];
            int x = 0;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] != t[k]) {
                    x ++;
                    if (x > 2) break;
                }
            }
            if (x <= 2) {
                x = f[i];
                while (x != f[x]) {
                    x = f[x];
                }
                auto y = f[j];
                while (y != f[y]) {
                    y = f[y];
                }
                if (x != y) {
                    res --;
                    f[y] = x;
                }
            }
        }
    }
    return res;
}