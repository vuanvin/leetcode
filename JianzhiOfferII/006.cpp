#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
        int a = numbers[i];
        int b = numbers[j];
        if (a + b == target) {
            return {i, j};
        } else if (a + b < target) {
            i++;
        } else {
            j--;
        }
    }
    return {};
}