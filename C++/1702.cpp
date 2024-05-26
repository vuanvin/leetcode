#include <leetcode.h>

class Solution {
public:
    // string maximumBinaryString(string binary) {
    //     int n = binary.size(), i = 0;
    //     while (i < n && binary[i] != '0') {
    //         i++;
    //     }
    //     int j = i + 1;
    //     while (j < n && binary[j] != '0') {
    //         j++;
    //     }
    //     while (j < n) {
    //         binary[i] = binary[j] = '1';
    //         binary[i + 1] = '0';
    //         i = i + 1;
    //         j = j + 1;

    //         while (j < n && binary[j] != '0') {
    //             j++;
    //         }
    //     }
    //     return binary;
    // }

    string maximumBinaryString(string binary) {
        int n = binary.size(), st = 0, cnt = 0;
        while (st < n && binary[st] != '0') {
            st++;
        }
        for (int i = 0; i < n; i++) {
            if (binary[i] == '0') {
                cnt++;
            }
        }
        string ans(n, '1');
        if (cnt > 0) {
            ans[st + cnt - 1] = '0';
        }
        return ans;
    }
};