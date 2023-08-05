#include <leetcode.h>

class Solution {
public:
    vector<vector<int>> memory;
    vector<int> bin_seats;

    int f(int X, int row_num, int width) {
        if (memory[row_num][X] != -1) {
            return memory[row_num][X];
        }
        int ans = 0;
        for (int students = 0; students < (1 << width); students++) {
            if (students & ~X || students & (students << 1)) continue;
            int numSited = 0;
            for (int j = 0; j < width; j++) {
                if ((1 << j) & students) numSited++;
            }
            if (row_num == bin_seats.size() - 1) {
                ans = max(ans, numSited);
            } else {
                int Y = bin_seats[row_num + 1];  // new seat row
                Y &= ~(students << 1);
                Y &= ~(students >> 1);
                ans = max(ans, numSited + f(Y, row_num + 1, width));
            }
        }
        memory[row_num][X] = ans;
        return ans;
    }
    int compress(const vector<char>& row) {
        int ans = 0;
        for (char c : row) {
            ans <<= 1;
            if (c == '.') {
                ++ans;
            }
        }
        return ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        memory.assign(m, vector<int>(1 << n, -1));
        for (const auto& row : seats) {
            bin_seats.push_back(compress(row));
        }
        return f(bin_seats[0], 0, n);
    }
};