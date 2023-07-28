use crate::leetcode::Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.len() == 0 {
            return 0;
        }
        let (mut f0, mut f1, mut f2) = (-prices[0], 0, 0);
        for p in &prices[1..] {
            let (n0, n1, n2) = (f0.max(f2 - p), f0 + p, f1.max(f2));
            f0 = n0;
            f1 = n1;
            f2 = n2;
        }
        f1.max(f2)
    }
}
