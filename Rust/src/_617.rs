use crate::leetcode::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn merge_trees(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root1.is_none() {
            root2
        } else if root2.is_none() {
            root1
        } else {
            let b1 = root1.unwrap();
            let b2 = root2.unwrap();
            let r1 = b1.borrow();
            let r2 = b2.borrow();
            let sum = r1.val + r2.val;
            let mut root = TreeNode::new(sum);
            root.left = Self::merge_trees(r1.left.clone(), r2.left.clone());
            root.right = Self::merge_trees(r1.right.clone(), r2.right.clone());
            Some(Rc::new(RefCell::new(root)))
        }
    }
}
