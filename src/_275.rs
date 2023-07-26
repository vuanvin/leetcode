use crate::leetcode::Solution;

impl Solution {
    pub fn h_index_2(citations: Vec<i32>) -> i32 {
        let n = citations.len() as i32;
        let (mut l, mut r) = (0, n - 1);
        if citations[r as usize] == 0 {
            return 0;
        }
        while l < r {
            let m = (l + r) / 2;
            let cond = citations[m as usize] >= (n - m);
            if !cond {
                l = m + 1
            } else {
                r = m
            }
        }
        n - l
    }
}
