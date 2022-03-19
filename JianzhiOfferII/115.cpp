#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> reflect(n+1, 0);
        vector<int> partial(n, 0);

        for (int i = 0; i < n; i++) { reflect[org[i]] = i; }

        for (auto& seq : seqs) {
            int len = seq.size();
            int ru = -1;
            for (auto v : seq) {
                if (v < 1 || v > n) return false;
                auto rv = reflect[v];
                if (ru >= rv) return false;
                if (ru == rv - 1) {
                    partial[rv] = 1;
                }

                ru = rv;
            }
        }

        return (accumulate(partial.begin(), partial.end(), 0) == n);
    }
};