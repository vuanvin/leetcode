#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int len = max(a.size(), b.size());
    a = string(len - a.size(), '0') + a;
    b = string(len - b.size(), '0') + b;

    int carry = 0;
    for (int i = len-1; i >= 0; i--) {
        int an = a[i] == '1' ? 1 : 0;
        int bn = b[i] == '1' ? 1 : 0;
        int sum = carry + an + bn;
        if (sum == 3) {
            carry = 1;
            a[i] = '1';
        } else if (sum == 2) {
            carry = 1;
            a[i] = '0';
        } else if (sum == 1) {
            carry = 0;
            a[i] = '1';
        }
    }
    if (carry) {
        a = "1" + a;
    }
    return a;
}

int main() {
    cout << addBinary("10011", "1011001") << endl;
}