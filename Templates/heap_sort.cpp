#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int i, int n) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void heap_sort(vector<int>& arr) {
    // build max heap
    int n = arr.size();
    for (int i = n / 2; i >= 0; i--) {
        heapify(arr, i, n);
    }
    // sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {
    vector<int> arr;
    int n = 10;
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100);
    }
    heap_sort(arr);
    for (auto v : arr) {
        cout << v << endl;
    }
}