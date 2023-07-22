#include <leetcode.h>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> numNeed(numCourses, 0);
        unordered_map<int, vector<int>> req;
        queue<int> proc;
        for (auto& p : prerequisites) {
            numNeed[p[0]]++;
            req[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (numNeed[i] == 0) proc.push(i);
        }
        while (!proc.empty()) {
            auto u = proc.front();
            proc.pop();
            for (auto v : req[u]) {
                if (--numNeed[v] == 0) proc.push(v);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (numNeed[i] > 0) return false;
        }
        return true;
    }
};