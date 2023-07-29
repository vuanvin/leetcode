use crate::leetcode::Solution;

use std::collections::HashMap;

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut mp = HashMap::new();
        s.chars().enumerate().for_each(|(i, c)| {
            mp.entry(c).and_modify(|x| *x = s.len()).or_insert(i);
        });
        let ret = mp.values().into_iter().reduce(|a, b| a.min(b)).unwrap();
        return if ret.eq(&s.len()) { -1 } else { *ret as i32 };
    }

    // pub fn first_uniq_char(s: String) -> i32 {
    //     let mut mp = HashMap::new();

    //     s.chars().for_each(|c| {
    //         mp.entry(c).and_modify(|x| *x = 2).or_insert(1);
    //     });

    //     let mut ret = -1;
    //     s.chars().enumerate().for_each(|(i, c)| {
    //         let num = mp.entry(c).or_default();
    //         if num < &mut 2 && ret == -1 {
    //             ret = i as i32;
    //         }
    //     });
    //     ret
    // }
}
