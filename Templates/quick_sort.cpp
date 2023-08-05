#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int n) {
    if (n <= 1) return;
    int l = 0, pivot = arr[0];
    for (int h = 1; h < n; ++h) {
        if (arr[h] <= pivot) {
            ++l;
            swap(arr[l], arr[h]);
        }
    }
    swap(arr[l], arr[0]);
    quick_sort(arr, l);
    quick_sort(arr + l + 1, n - 1 - l);
}

void quick_sort2(int arr[], int n) {
    if (n <= 1) return;
    int l = 1, h = n - 1, pivot = arr[0];
    while (l < h) {
        while (l < h && arr[l] <= pivot) ++l;
        while (l < h && pivot < arr[h]) --h;
        swap(arr[l++], arr[h--]);
    }
    swap(arr[l - 1], arr[0]);
    quick_sort2(arr, l - 1);
    quick_sort2(arr + l, n - l);
}

int main() {
    constexpr int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    quick_sort(arr, 10);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}