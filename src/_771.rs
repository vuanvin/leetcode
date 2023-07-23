use crate::leetcode::Solution;

use std::collections::HashSet;
impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut ans: i32 = 0;
        let mut js = HashSet::new();
        for jewel in jewels.as_bytes().iter() {
            js.insert(jewel);
        }
        for stone in stones.as_bytes().iter() {
            if js.contains(stone) {
                ans += 1;
            }
        }
        ans
    }
}
