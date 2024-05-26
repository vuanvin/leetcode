#include <leetcode.h>

class SnapshotArray {
    int snap_time;
    vector<vector<pair<int, int>>> arr;
    vector<int> up_set;

public:
    SnapshotArray(int length) {
        arr.assign(length, vector<pair<int, int>>(1, {-1, 0}));
        up_set.resize(length);
        iota(up_set.begin(), up_set.end(), 0);
        snap_time = -1;
    }

    void set(int index, int val) {
        if (arr[index].back().first == -1) {
            arr[index].back().second = val;
        } else {
            arr[index].emplace_back(-1, val);
            up_set.push_back(index);
        }
    }

    int snap() {
        ++snap_time;

        for (auto up_id : up_set) {
            arr[up_id].back().first = snap_time;
        }
        up_set.clear();

        return snap_time;
    }

    int get(int index, int snap_id) {
        int l = 0, r = arr[index].size() - 1;
        if (arr[index][r].first == -1) {
            r--;
        }
        while (l < r) {
            int m = (l + r + 1) / 2;
            int id = arr[index][m].first;

            if (id > snap_id) {
                r = m - 1;
            } else {
                l = m;
            }
        }

        return arr[index][r].second;
    }
};