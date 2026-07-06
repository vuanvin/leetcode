use crate::leetcode::Solution;

impl Solution {
    pub fn to_hex(num: i32) -> String {
        if num == 0 {
            return String::from("0");
        }
        let mut s = String::new();
        let mut num = num;
        let mut i = 0;
        while num != 0 && i < 8 {
            let v = num & 0x0f;
            let ch = if v < 10 {
                v.to_string()
            } else {
                (((v - 10) as u8 + 'a' as u8) as char).to_string()
            };
            s += ch.as_str();
            num >>= 4;
            i += 1;
        }
        s.chars().rev().collect::<String>()
    }
}
