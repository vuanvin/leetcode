mod leetcode;
mod _1;

fn main() {
    let nums = vec![12, 3, 4, 5, 8, 9, 14];
    let target = 19;
    let result = leetcode::Solution::two_sum(nums, target);
    println!("result: {:?}", result);
}