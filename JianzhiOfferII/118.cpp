#include <bits/stdc++.h>
using namespace std;

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, int> vset;
    for (auto e : edges) {
        int a = e[0], b = e[1];
        if (vset.count(a) && vset.count(b)) {
            auto fa = vset[a], fb = vset[b];
            while (fa != vset[fa]) { fa = vset[fa]; }
            while (fb != vset[fb]) { fb = vset[fb]; }
            if (fa == fb) { return e; }
            vset[fb] = fa;
            vset[a] = fa;
            vset[b] = fa;
        } else if (vset.count(a)) {
            vset[b] = a;
        } else if (vset.count(b)) {
            vset[a] = b;
        } else {
            vset[a] = a;
            vset[b] = a;
        }
    }
    return edges.back();
}