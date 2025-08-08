use crate::leetcode::Solution;

impl Solution {
    #[allow(unused_mut)]
    pub fn max_strength(mut nums: Vec<i32>) -> i64 {
        if nums.len() == 1{
            return nums[0] as i64;
        }

        let mut neg: i64 = 1;
        let mut max_neg = 0;
        let mut num_neg = 0;

        let mut pos: i64 = 1;
        let mut num_pos = 0;

        for num in nums {
            if num < 0 {
                neg *= num as i64;
                num_neg += 1;
                if max_neg == 0 || num > max_neg {
                    max_neg = num;
                }
            } else if num > 0 {
                pos *= num as i64;
                num_pos += 1;
            }
        }

        if num_neg <= 1{
            if num_pos > 0 {
                return pos;
            } else {
                return 0;
            }
        }

        if neg < 0 {
            neg /= max_neg as i64;
        }

        return pos * neg;
    }
}