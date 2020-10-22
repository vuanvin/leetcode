package com.leet102;

import com.leetcode.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null) return res;
        view(res, root,0);
        return res;
    }
    public void view(List<List<Integer>> res, TreeNode root, int depth) {
        if (root == null) return;;
        if (res.size() > depth) {
            List<Integer> r = res.get(depth);
            r.add(root.val);
        } else {
            var r = new ArrayList<Integer>();
            r.add(root.val);
            res.add(r);
        }
        view(res, root.left, depth+1);
        view(res, root.right, depth+1);
    }
}
