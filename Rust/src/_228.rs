use crate::leetcode::Solution;

impl Solution {
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        let mut ans = Vec::<String>::new();
        if nums.len() == 0 {
            return ans;
        }
        let mut s = nums[0].to_string();
        let (mut old, mut state) = (nums[0], 0);
        for i in 1..nums.len() {
            let val = nums[i];
            if val != old + 1 {
                if state == 1 {
                    s += "->";
                    s += old.to_string().as_str();
                    state = 0
                }
                ans.push(s);
                s = val.to_string();
            } else {
                state = 1
            }
            old = val;
        }
        if state == 1 {
            s += "->";
            s += old.to_string().as_str();
        }
        ans.push(s);
        ans
    }
}
