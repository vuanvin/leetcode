use crate::leetcode::Solution;

use std::collections::BinaryHeap;

impl Solution {
    pub fn halve_array(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut sum = 0;
        let mut heap = BinaryHeap::new();

        for v in nums {
            let u = (v as u64) << 20;
            heap.push(u);
            sum += u;
        }
        let half = sum / 2;
        while half < sum {
            let mx = heap.pop().unwrap();
            sum -= mx / 2;
            heap.push(mx / 2);
            ans += 1;
        }
        ans
    }
}
