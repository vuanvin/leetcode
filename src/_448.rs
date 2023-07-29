use crate::leetcode::Solution;

impl Solution {
    pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut nums = nums;
        for i in 0..nums.len() {
            let ii = i as i32;
            while nums[i] != ii + 1 && nums[i] != nums[nums[i] as usize - 1] {
                let j = nums[i] as usize - 1;
                let tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
        let mut i = 0;
        for j in 0..nums.len() {
            if nums[j] != j as i32 + 1 {
                nums[i] = j as i32 + 1;
                i += 1;
            }
        }
        while nums.len() > i {
            nums.pop();
        }
        nums
    }
}
