use crate::leetcode::Solution;

unsafe fn guess(num: i32) -> i32 {
    num
}

impl Solution {
    #[allow(non_snake_case)]
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut l, mut r) = (0, n);
        while l < r {
            let m = (r - l) / 2 + l;
            if guess(m) > 0 {
                l = m + 1
            } else {
                r = m;
            }
        }
        l
    }
}
