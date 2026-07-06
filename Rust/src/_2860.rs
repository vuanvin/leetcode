use crate::leetcode::Solution;

impl Solution {
    pub fn count_ways(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let mut ans = 0;

        for i in 0..=nums.len() {
            if i == 0 {
                if nums[i] > 0 {
                    ans += 1;
                }
                continue;
            }

            let num = &nums[i - 1];
            if *num < i as i32 {
                if i < nums.len() && nums[i] > i as i32 {
                    ans += 1;
                } else if i == nums.len() {
                    ans += 1;
                }
            }
        }

        return ans;
    }
}