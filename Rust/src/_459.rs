use crate::leetcode::Solution;

impl Solution {
    pub fn repeated_substring_pattern(s: String) -> bool {
        let li = s.as_bytes().into_iter().collect::<Vec<_>>();
        let mut next = vec![-1 as i32; li.len()];
        let (mut l, mut r) = (0, 1);
        while r < li.len() {
            next[r as usize] = l;
            if *li[l as usize] == *li[r as usize] {
                next[r] = next[next[r as usize] as usize];
                while next[r] >= 0 && *li[next[r] as usize] == *li[r as usize] {
                    next[r] = next[next[r as usize] as usize];
                }
            } else {
                l = next[l as usize];
                while l >= 0 && *li[l as usize] != *li[r] {
                    l = next[l as usize];
                }
            }
            l += 1;
            r += 1;
        }
        if l <= 0 {
            return false;
        }
        for i in 0..(r as i32 - l) {
            if *li[i as usize] != *li[(i + l) as usize] {
                return false;
            }
        }
        true
    }
}
