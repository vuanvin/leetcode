use crate::leetcode::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        fn dfs(node: Option<Rc<RefCell<TreeNode>>>, path: String, res: &mut Vec<String>) {
            if let Some(node) = node {
                let v = node.borrow().val;
                let mut new_path = path;
                new_path.push_str(&(v.to_string()));
                if node.borrow().left == None && node.borrow().right == None {
                    res.push(new_path.clone());
                }
                new_path.push_str("->");
                dfs(node.borrow_mut().left.take(), new_path.clone(), res);
                dfs(node.borrow_mut().right.take(), new_path.clone(), res);
            }
        }
        let p = String::new();
        let mut ans = Vec::new();
        dfs(root, p, &mut ans);
        ans
    }
}
