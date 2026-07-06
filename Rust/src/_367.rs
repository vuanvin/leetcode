use crate::leetcode::Solution;

impl Solution {
    pub fn is_perfect_square(num: i32) -> bool {
        let (mut l, mut h) = (0, num);
        while l <= h {
            let m = (l + h) / 2;
            let s = m as i64 * m as i64;
            if s < num as i64 {
                l = m + 1;
            } else if s > num as i64 {
                h = m - 1;
            } else {
                return true;
            }
        }
        return false;
    }
}
