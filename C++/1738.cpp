#include <leetcode.h>

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            matrix[i][0] = matrix[i][0] ^ matrix[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            matrix[0][j] = matrix[0][j] ^ matrix[0][j - 1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i][j] ^ matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
            }
        }
        priority_queue<int, vector<int>, greater<int>> Q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (Q.size() < k) {
                    Q.push(matrix[i][j]);
                } else if (matrix[i][j] > Q.top()) {
                    Q.pop();
                    Q.push(matrix[i][j]);
                }
            }
        }
        return Q.top();
    }
};