use crate::leetcode::Solution;

use std::collections::HashMap;
impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = Vec::<i32>::new();
        let mut em = HashMap::<i32, Vec<i32>>::new();
        for i in 0..n {
            em.insert(i, Vec::<i32>::new());
        }
        for edge in edges.iter() {
            em.entry(edge[0]).and_modify(|side| side.push(edge[1]));
            em.entry(edge[1]).and_modify(|side| side.push(edge[0]));
        }
        let mut height = vec![0; n as usize];
        let mut source = vec![-1; n as usize];
        fn visit(
            curr: i32,
            prev: i32,
            em: &HashMap<i32, Vec<i32>>,
            height: &mut Vec<i32>,
            source: &mut Vec<i32>,
        ) -> i32 {
            let mut mx = 0;
            for next in em.get(&curr).unwrap() {
                let next = *next;
                if next != prev {
                    let num = visit(next, curr, em, height, source);
                    if num > mx {
                        source[curr as usize] = next;
                        mx = num
                    } else if num == mx {
                        source[curr as usize] = -1;
                    }
                }
            }
            height[curr as usize] = mx + 1;
            height[curr as usize]
        }
        fn revisit(
            curr: i32,
            prev: i32,
            em: &HashMap<i32, Vec<i32>>,
            height: &mut Vec<i32>,
            source: &mut Vec<i32>,
        ) {
            let mut mx = if prev == -1 {
                1
            } else {
                height[prev as usize] + 1
            };

            let so = if height[curr as usize] <= mx {
                height[curr as usize] = mx;
                -1
            } else {
                source[curr as usize]
            };

            for next in em.get(&curr).unwrap() {
                let next = *next;
                if next != prev && so != next {
                    mx = mx.max(height[next as usize] + 1);
                    revisit(next, curr, em, height, source);
                }
            }

            if so != -1 {
                let temp = height[curr as usize];
                height[curr as usize] = mx;
                revisit(so, curr, em, height, source);
                height[curr as usize] = temp;
            }
        }
        visit(0, -1, &em, &mut height, &mut source);
        revisit(0, -1, &em, &mut height, &mut source);

        let mut mn = height[0];
        for h in height.iter() {
            mn = mn.min(*h);
        }
        for i in 0..n {
            if height[i as usize] == mn {
                ans.push(i);
            }
        }
        ans
    }
}
