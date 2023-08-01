#include <leetcode.h>

class Solution {
public:
    using pii = pair<int, int>;
    struct Hash {
        size_t operator()(const pii& x) const { return x.first ^ x.second; }
    };
    using pii_set = unordered_set<pii, Hash>;
    bool ans = false;

    pii_set comp(pii u, pii v) {
        pii_set res;
        res.emplace(u.first * v.second + u.second * v.first, u.second * v.second);
        res.emplace(u.first * v.second - u.second * v.first, u.second * v.second);
        res.emplace(u.first * v.first, u.second * v.second);
        if (v.first != 0) {
            res.emplace(u.first * v.second, u.second * v.first);
        }
        swap(u, v);
        res.emplace(u.first * v.second - u.second * v.first, u.second * v.second);
        if (v.first != 0) {
            res.emplace(u.first * v.second, u.second * v.first);
        }
        return res;
    }

    void dfs(const pii_set& res, const vector<pii>& nums) {
        if (nums.size() == 0) {
            for (auto v : res) {
                if (v.first == v.second * 24) {
                    ans = true;
                    return;
                }
            }
            return;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto temp = nums;
            temp.erase(temp.begin() + i);
            for (auto v : res) {
                dfs(comp(nums[i], v), temp);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                auto vset = comp(nums[i], nums[j]);
                for (auto u : res) {
                    for (auto v : vset) {
                        for (auto r : comp(u, v)) {
                            if (r.second * 24 == r.first) {
                                ans = true;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    bool judgePoint24(vector<int>& cards) {
        ans = false;

        vector<pii> nums;
        for (auto c : cards) {
            nums.emplace_back(c, 1);
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                auto temp = nums;
                temp.erase(temp.begin() + j);
                temp.erase(temp.begin() + i);
                dfs(comp(nums[i], nums[j]), temp);
            }
        }

        return ans;
    }
};

// class Solution {
// public:
//     using pii = pair<int, int>;
//     bool ans;

//     void dfs(vector<pii> nums) {
//         int n = nums.size();
//         if (n == 1) {
//             cout << nums[0].first / nums[0].second << endl;
//             if (nums[0].first == nums[0].second * 24) {
//                 ans = true;
//             }
//             return;
//         }

//         pii res;
//         vector<pii> arg(n - 1);

//         for (int i = 0; i < n - 1; i++) {
//             auto u = nums[i], v = nums[i + 1];
//             res = {u.first * v.second + u.second * v.first, u.second * v.second};

//             std::copy(nums.begin(), nums.begin() + i, arg.begin());
//             arg[i] = res;
//             std::copy(nums.begin() + i + 2, nums.end(), arg.begin() + i + 1);
//             dfs(arg);

//             res = {u.first * v.second - u.second * v.first, u.second * v.second};

//             std::copy(nums.begin(), nums.begin() + i, arg.begin());
//             arg[i] = res;
//             std::copy(nums.begin() + i + 2, nums.end(), arg.begin() + i + 1);
//             dfs(arg);

//             res = {u.first * v.first, u.second * v.second};

//             std::copy(nums.begin(), nums.begin() + i, arg.begin());
//             arg[i] = res;
//             std::copy(nums.begin() + i + 2, nums.end(), arg.begin() + i + 1);
//             dfs(arg);

//             if (v.first != 0) {
//                 res = {u.first * v.second, u.second * v.first};

//                 std::copy(nums.begin(), nums.begin() + i, arg.begin());
//                 arg[i] = res;
//                 std::copy(nums.begin() + i + 2, nums.end(), arg.begin() + i + 1);
//                 dfs(arg);
//             }
//         }
//     }

//     bool judgePoint24(vector<int>& cards) {
//         vector<pii> nums;
//         ans = false;

//         for (auto c : cards) {
//             nums.emplace_back(c, 1);
//         }

//         dfs(nums);
//         return ans;
//     }
// };
