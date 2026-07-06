use crate::leetcode::Solution;

impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut ans = 0;
        let (mut x, mut y) = (x, y);
        while x > 0 || y > 0 {
            if x & 1 != y & 1 {
                ans += 1;
            }
            x >>= 1;
            y >>= 1;
        }
        ans
    }
}
