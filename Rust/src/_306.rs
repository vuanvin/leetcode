use crate::leetcode::Solution;

impl Solution {
    pub fn is_additive_number(num: String) -> bool {
        fn backtrace(i: usize, n: u32, first: u32, second: u32, num: &String) -> bool {
            if i == num.len() {
                return n >= 3;
            }
            let mut ret = false;
            let mut sum = 0;
            for j in i..num.len() {
                sum = sum * 10 + num.chars().nth(j).unwrap().to_digit(10).unwrap();
                if n == 0 {
                    ret |= backtrace(j + 1, n + 1, sum, 0, num);
                } else if n == 1 {
                    ret |= backtrace(j + 1, n + 1, first, sum, num);
                } else {
                    if first + second == sum {
                        ret |= backtrace(j + 1, n + 1, second, sum, num)
                    }
                }
                if sum == 0 {
                    break;
                }
            }
            ret
        }
        backtrace(0, 0, 0, 0, &num)
    }
}
