use crate::leetcode::Solution;

impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        let mut ans = vec![area, 1];
        for i in 1..=(area as f64).sqrt() as i32 {
            if area % i == 0 {
                ans[0] = area / i;
                ans[1] = i;
            }
        }
        ans
    }
}
