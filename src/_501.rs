use crate::leetcode::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans = Vec::<i32>::new();
        let mut record = (0, 0, 0);
        let mut start = 0;
        fn preorder(
            node: Option<Rc<RefCell<TreeNode>>>,
            record: &mut (i32, i32, i32),
            start: &mut i32,
            ans: &mut Vec<i32>,
        ) {
            if node.is_none() {
                return;
            }
            let left = node.clone().unwrap().borrow().left.clone();
            let right = node.clone().unwrap().borrow().right.clone();
            preorder(left, record, start, ans);
            let new_val = node.clone().unwrap().borrow().val;
            let old_val = record.0;
            if *start == 0 {
                *start = 1;
                *record = (new_val, 1, 1);
                ans.push(new_val);
            } else {
                if new_val == old_val {
                    record.1 += 1;
                    if record.1 > record.2 {
                        ans.clear();
                        ans.push(new_val);
                        record.2 = record.1;
                    } else if record.1 == record.2 {
                        ans.push(new_val);
                    }
                } else {
                    record.0 = new_val;
                    record.1 = 1;
                    if record.1 == record.2 {
                        ans.push(new_val);
                    }
                }
            }
            preorder(right, record, start, ans);
        }
        preorder(root, &mut record, &mut start, &mut ans);
        ans
    }
}
