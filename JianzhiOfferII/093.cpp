#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                int a = arr[j];
                int cnt = 2;
                while (binary_search(arr.begin() + j, arr.end(), sum)) {
                    int b = sum;
                    sum += a;
                    a = b;
                    cnt++;
                }
                if (cnt >= 3) ans = max(ans, cnt);
            }
        }

        return ans;
    }
};