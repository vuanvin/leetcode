use crate::leetcode::Solution;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

unsafe fn guess(num: i32) -> i32 {
    num
}

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let (mut l, mut r) = (0, n);
        while l < r {
            let m = (r - l) / 2 + l;
            if (guess(m) > 0) {
                l = m + 1
            } else {
                r = m;
            }
        }
        l
    }
}
