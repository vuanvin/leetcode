#include <leetcode.h>

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        using PII = pair<int, int>;  // (id, time)
        auto wait_priority_cmp = [&](int x, int y) {
            auto time_x = time[x][0] + time[x][2];
            auto time_y = time[y][0] + time[y][2];
            return time_x != time_y ? time_x < time_y : x < y;
        };
        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp), wait_right(wait_priority_cmp);
        auto work_priority_cmp = [&](const PII& x, const PII& y) { return x.second > y.second; };
        priority_queue<PII, vector<PII>, decltype(work_priority_cmp)> work_left(work_priority_cmp), work_right(work_priority_cmp);
        for (int i = 0; i < k; ++i) wait_left.push(i);
        int curr_time = 0;
        while (n > 0 || !work_right.empty() || !wait_right.empty()) {
            while (!work_left.empty() && work_left.top().second <= curr_time) {
                wait_left.push(work_left.top().first);
                work_left.pop();
            }
            while (!work_right.empty() && work_right.top().second <= curr_time) {
                wait_right.push(work_right.top().first);
                work_right.pop();
            }
            if (!wait_right.empty()) {
                int id = wait_right.top();
                wait_right.pop();
                curr_time += time[id][2];
                work_left.push({id, curr_time + time[id][3]});
            } else if (n > 0 && !wait_left.empty()) {
                int id = wait_left.top();
                wait_left.pop();
                curr_time += time[id][0];
                work_right.push({id, curr_time + time[id][1]});
                --n;
            } else {
                auto next_time = INT_MAX;  // maybe next time
                if (!work_left.empty()) {
                    next_time = min(next_time, work_left.top().second);
                }
                if (!work_right.empty()) {
                    next_time = min(next_time, work_right.top().second);
                }
                if (next_time != INT_MAX) {
                    curr_time = max(curr_time, next_time);
                }
            }
        }
        return curr_time;
    }
};