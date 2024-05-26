#include <leetcode.h>

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        constexpr int N = 1e9 + 7;
        vector<int> s(n - 1, 0);
        int f = 2;
        for (int i = 1; i < n - 1; i++) {
            s[i] = (s[i - 1] + f) % N;
            int ni = nextVisit[i];
            f = (2 + s[i] + N - s[ni]) % N;
        }
        return (s[n - 2] + f) % N;
    }
};