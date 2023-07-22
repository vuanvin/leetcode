use crate::leetcode::Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash_map = std::collections::HashMap::new();
        nums.into_iter()
            .enumerate()
            .find_map(|(i, x)| match hash_map.get(&(target - x)) {
                Some(j) => Some(vec![*j, i as i32]),
                None => {
                    hash_map.insert(x, i as i32);
                    None
                }
            })
            .unwrap()
    }
}
