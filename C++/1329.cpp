#include <leetcode.h>

class Solution {
public:
    // vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    //     int m = mat.size(), n = mat[0].size();
    //     for (int fi = 0, fj = 0; fj < n; fj++) {
    //         int si = fi, sj = fj;

    //         while (si < m - 1 && sj < n - 1) {
    //             int i = si + 1, j = sj + 1;
    //             while (i < m && j < n) {
    //                 if (mat[si][sj] > mat[i][j]) {
    //                     swap(mat[si][sj], mat[i][j]);
    //                 }
    //                 i++;
    //                 j++;
    //             }
    //             si++;
    //             sj++;
    //         }
    //     }

    //     for (int fi = 1, fj = 0; fi < m; fi++) {
    //         int si = fi, sj = fj;

    //         while (si < m - 1 && sj < n - 1) {
    //             int i = si + 1, j = sj + 1;
    //             while (i < m && j < n) {
    //                 if (mat[si][sj] > mat[i][j]) {
    //                     swap(mat[si][sj], mat[i][j]);
    //                 }
    //                 i++;
    //                 j++;
    //             }
    //             si++;
    //             sj++;
    //         }
    //     }

    //     return mat;
    // }

    void qsort(vector<vector<int>>& mat, int l, int h, int d) {
        if (l == h) return;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0, j = 0; j < n; j++) {
            qsort(mat, 0, min(m - 1, n - i), j);
        }

        for (int i = 1, j = 0; i < m; i++) {
            qsort(mat, i, min(m - 1, n), -j);
        }
    }
};