#include <leetcode.h>

class Solution1 {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        set<int> unique_days;
        vector<pair<int, int>> start_days, end_days;
        for (int i = 0; i < events.size(); ++i) {
            unique_days.insert(events[i][0] - 1);
            unique_days.insert(events[i][1]);
        }
        sort(events.begin(), events.end(), [](const auto &x, const auto &y) { return x[1] < y[1]; });
        vector<int> ordered_days(unique_days.begin(), unique_days.end());
        unordered_map<int, int> day2id;
        for (int i = 0; i < ordered_days.size(); ++i) {
            day2id[ordered_days[i]] = i;
        }
        int n = ordered_days.size();
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; ++i) {
            for (int event_id = 0, curr_id = 1; curr_id < n; ++curr_id) {
                auto curr_day = ordered_days[curr_id];
                dp[i][curr_id] = dp[i][curr_id - 1];
                for (; event_id < events.size() && events[event_id][1] == curr_day; ++event_id) {
                    int val = events[event_id][2];
                    int prev_day = events[event_id][0] - 1;
                    int prev_id = day2id[prev_day];
                    dp[i][curr_id] = max(dp[i][curr_id], dp[i - 1][prev_id] + val);
                }
            }
        }
        return dp[k][ordered_days.size() - 1];
    }
};

class Solution {
public:
    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin(), events.end(), [](const auto &x, const auto &y) { return x[1] < y[1]; });
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, 0));
        for (int i = 0; i < events.size(); ++i) {
            int p = lower_bound(events.begin(), events.begin() + i, events[i][0], [](const auto &x, int val) { return x[1] < val; }) - events.begin();
            for (int j = 1; j <= k; ++j) {
                dp[i + 1][j] = max(dp[i][j], dp[p][j - 1] + events[i][2]);
            }
        }
        return dp[events.size()][k];
    }
};