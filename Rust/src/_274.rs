use crate::leetcode::Solution;

impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut nums = citations.clone();
        nums.sort_by(|a, b| b.partial_cmp(a).unwrap());
        for (i, cit) in nums.iter().enumerate() {
            let num = i as i32 + 1;
            if *cit >= num {
                ans = std::cmp::max(ans, num);
            }
        }
        ans
    }
}
