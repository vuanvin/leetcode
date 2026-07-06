use crate::leetcode::{Solution, TreeNode};

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root {
            let node_ref = node.borrow();
            if node_ref.val == val {
                return Some(node.clone());
            } else if node_ref.val < val {
                return Self::search_bst(node_ref.right.clone(), val);
            } else {
                return Self::search_bst(node_ref.left.clone(), val);
            }
        }
        None
    }

    pub fn search_bst2(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        let mut current = root;
        while let Some(node) = current {
            let node_ref = node.borrow();
            if node_ref.val == val {
                return Some(node.clone());
            } else if node_ref.val < val {
                current = node_ref.right.clone();
            } else {
                current = node_ref.left.clone();
            }
        }
        None
    }
}
