#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;

        unordered_map<string, int> indexs;
        unordered_map<int, int> edges;
        unordered_map<int, double> weights;

        int num_var = 0;
        int n = equations.size();

        auto Find = [&](int x) {
            double prod = 1;
            while (edges[x] != x) {
                prod *= weights[x];
                x = edges[x];
            }
            return make_pair(x, prod);
        };

        auto Add = [&](string& s) {
            indexs[s] = num_var;
            edges[num_var] = num_var;
            weights[num_var] = 1.0;
            num_var++;
        };

        for (int i = 0; i < n; i++) {
            auto& equation = equations[i];
            double val = values[i];
            auto& u = equation[0];
            auto& v = equation[1];

            if (!indexs.count(u)) { Add(u); }
            if (!indexs.count(v)) { Add(v); }

            int a = indexs[u];
            int b = indexs[v];

            auto fa = Find(a);
            auto fb = Find(b);

            if (fa.first != fb.first) {
                edges[fa.first] = fb.first;
                weights[fa.first] = fb.second * val / fa.second;
            }

        }

        for (auto query : queries) {
            auto& u = query[0];
            auto& v = query[1];

            if (!indexs.count(u) || !indexs.count(v)) {
                res.push_back(-1);
                continue;
            }

            auto a = indexs[u], b = indexs[v];

            auto fa = Find(a);
            auto fb = Find(b);

            if (fa.first != fb.first) {
                res.push_back(-1);
                continue;
            }

            res.push_back(fa.second / fb.second);
        }

        return res;
    }
};