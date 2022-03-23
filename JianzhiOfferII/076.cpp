#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};

class Solution_1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> k_nums(nums.begin(), nums.begin() + k);
        make_heap(k_nums.begin(), k_nums.end(), greater<int>());

        int n = nums.size();
        for (int i = k; i < n; i++) {
            if (nums[i] > k_nums[0]) {
                k_nums[0] = nums[i];
                make_heap(k_nums.begin(), k_nums.end(), greater<int>());

            }
        }

        sort(k_nums.begin(), k_nums.end());
        return k_nums[0];
    }
};