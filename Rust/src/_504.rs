use crate::leetcode::Solution;

impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        if num == 0 {
            return String::from("0");
        }
        let (sign, mut num) = if num >= 0 { (1, num) } else { (-1, -num) };
        let mut ans = String::new();
        while num > 0 {
            ans += (num % 7).to_string().as_str();
            num /= 7;
        }
        ans = ans.chars().rev().collect();
        if sign < 0 {
            String::from("-") + ans.to_string().as_str()
        } else {
            ans
        }
    }
}
