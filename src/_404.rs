use crate::leetcode::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn sum_of_left_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        match root {
            Some(_) => {
                let root = root.clone().unwrap();
                let mut val = 0;
                let left = root.as_ref().borrow().left.clone();
                let right = root.as_ref().borrow().right.clone();
                if left.is_some() {
                    let ll = left.clone().unwrap().as_ref().borrow().left.clone();
                    let lr = left.clone().unwrap().as_ref().borrow().right.clone();

                    if ll.is_none() && lr.is_none() {
                        val += left.clone().unwrap().as_ref().borrow().val;
                    } else {
                        val += Self::sum_of_left_leaves(left.clone());
                    }
                }
                if right.is_some() {
                    val += Self::sum_of_left_leaves(right.clone());
                }
                val
            }
            None => 0,
        }
    }
}
