use crate::leetcode::Solution;

impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut ans = 0;
        let (mut l, mut r) = (0 as usize, n - 1);
        let (mut hl, mut hr) = (height[l], height[r]);
        while l < r {
            if hl < hr {
                l += 1;
                if height[l] < hl {
                    ans += hl - height[l];
                } else {
                    hl = height[l];
                }
            } else {
                r -= 1;
                if height[r] < hr {
                    ans += hr - height[r];
                } else {
                    hr = height[r];
                }
            }
        }
        ans
    }
}
