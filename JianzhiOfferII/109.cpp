#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock_1(vector<string>& deadends, string target) {
        int N = 10000, n = 4;
        vector<vector<int>> graph(N, vector<int>());

        auto prev = [=](int x, int num) {
            int y = (x / num) % 10;
            x += (y == 0) ? 9 * num : -num;
            return x;
        };

        auto next = [=](int x, int num) {
            int y = (x / num) % 10;
            x += (y == 9) ? -9 * num : num;
            return x;
        };

        for (int i = 0; i < N; i++) {
            for (int b = 0; b < n; b++) {
                int num = pow(10, b);
                graph[i].push_back(next(i, num));
                graph[i].push_back(prev(i, num));
            }
        } 

        for (auto& dead : deadends) {
            auto num = stoi(dead);
            graph[num].clear();
        }

        int goal = stoi(target);

        queue<int> Q;
        Q.push(0);
        int t = 1;

        int ans = 0;
        while (t) {
            for (int i = 0; i < t; i++) {
                auto u = Q.front(); Q.pop();
                if (u == goal) return ans;
                for (auto v : graph[u]) {
                    Q.push(v);
                }
                graph[u].clear();
            }
            t = Q.size();
            ans++;
        }

        return -1;
    }

    int openLock(vector<string>& deadends, string target) {
        int N = 10000, n = 4;
        vector<vector<int>> graph(N, vector<int>());

        auto prev = [=](int x, int num) {
            int y = (x / num) % 10;
            x += (y == 0) ? 9 * num : -num;
            return x;
        };

        auto next = [=](int x, int num) {
            int y = (x / num) % 10;
            x += (y == 9) ? -9 * num : num;
            return x;
        };

        for (int i = 0; i < N; i++) {
            for (int b = 0; b < n; b++) {
                int num = pow(10, bit);
                graph[i].push_back(next(i, num));
                graph[i].push_back(prev(i, num));
            }
        } 

        for (auto& dead : deadends) {
            auto num = stoi(dead);
            graph[num].clear();
        }

        int goal = stoi(target);
        if (goal == 0) return 0;

        queue<int> Q;
        Q.push(0);
        int t = 1;

        int ans = 1;
        while (t) {
            for (int i = 0; i < t; i++) {
                auto u = Q.front(); Q.pop();
                if (u == goal) return ans;
                for (auto v : graph[u]) {
                    Q.push(v);
                }
                graph[u].clear();
            }
            t = Q.size();
            ans++;
        }

        return -1;
    }
};