#include <bits/stdc++.h>
using namespace std;

int divide(int a, int b) {
    if (a == INT_MIN && b == -1) return INT_MAX;

    int res = 0;
    if (b == INT_MIN) {
        return a == b ? 1 : 0;
    }

    if (a == INT_MIN) {
        a -= -abs(b);
        res += 1;
    }
    int sign = (a > 0) ^ (b > 0) ? -1 : 1;

    int ua = abs(a);
    int ub = abs(b);
    for (int i = 31; i >= 0; i--) {
        if ((ua >> i) >= ub) {
            ua = ua - (ub << i);
            if (res > INT_MAX - (1 << i)) {
                return INT_MAX;
            }
            res += 1 << i;
        }
    }
    return sign == 1 ? res : -res;
}


int main() {
    int a = 739722, b = 9781;
    cout << divide(a, b) << endl;
}