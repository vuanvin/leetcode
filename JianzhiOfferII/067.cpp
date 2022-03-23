#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    int ans;

public:
    vector<int>::iterator remove_copy_if(vector<int>::iterator first, vector<int>::iterator last, vector<int>::iterator replace, function<bool(int)> pred) {
        first = find_if(first, last, pred);
        if (first == last) return last;
        auto result = first;
        *(replace++) = *first;
        ++ first;

        for (; first != last; first++) {
            if (!pred(*first)) {
                *result = *first;
                ++result;
            } else {
                *(replace++) = *first;
            }
        }
        return result;
    }
    void dfs(vector<int> & left, vector<int> & right, int base) {
        if (base == 0) {
            ans = max(ans, left[0] ^ right[0]);
            return;
        }

        auto pred = [&](int num) { return num & base; };

        auto lrn = count_if(left.begin(), left.end(), [&](int num) { return num & base; });
        auto rrn = count_if(right.begin(), right.end(), [&](int num) { return num & base; });

        vector<int> left_right(lrn);
        vector<int> right_right(rrn);

        auto lit = remove_copy_if(left.begin(), left.end(), left_right.begin(), pred);
        left.erase(lit, left.end());
        auto rit = remove_copy_if(right.begin(), right.end(), right_right.begin(), pred);
        right.erase(rit, right.end());

        base >>= 1;

        int lln = left.size();
        int rln = right.size();

        if (lrn && rln) {
            dfs(left_right, right, base);
        }
        if (lln && rrn) {
            dfs(left, right_right, base);
        }
        if (!lln && !rln) {
            dfs(left_right, right_right, base);
        }
        if (!lrn && !rrn) {
            dfs(left, right, base);
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        ans = 0;
        int base = (1 << 30);
        for ( ; base; base >>= 1) {
            bool key = false;
            for (auto num : nums) {
                if (base & num) {
                    key = true;
                    break;
                }
            }
            if (key) {
                auto pred = [&](int num) { return num & base; };
                auto ln = nums.size();
                auto rn = count_if(nums.begin(), nums.end(), pred);

                if (ln != rn && rn != 0) {
                    vector<int> right(rn);
                    auto it = remove_copy_if(nums.begin(), nums.end(), right.begin(), pred);
                    nums.erase(it, nums.end());

                    dfs(nums, right, base >>= 1);
                    return ans;
                }
            }
        }
        return ans;
    }
};