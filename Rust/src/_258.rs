use crate::leetcode::Solution;

impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        if num < 10 {
            num
        } else {
            Self::add_digits(num % 10 + Self::add_digits(num / 10))
        }
    }
}
