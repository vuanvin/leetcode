#include <leetcode.h>

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using pii = pair<int, int>;
        vector<int> arr{{1}};
        auto cmp = [&arr](const pii& x, const pii& y) { return (long long)x.first * arr[x.second] > (long long)y.first * arr[y.second]; };
        priority_queue<pii, vector<pii>, decltype(cmp)> q(cmp);
        for (auto p : primes) q.emplace(p, 0);
        while (arr.size() < n) {
            auto [prime, idx] = q.top();
            q.pop();
            auto val = prime * arr[idx];
            if (arr.back() != val) arr.push_back(val);
            q.emplace(prime, idx + 1);
        }
        return arr[n - 1];
    }
};