# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from leetcode.TreeNode import TreeNode


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if p.val > q.val:
            t = p
            p = q
            q = t

        while True:
            if root == p or root == q:
                return root
            elif root.val < p.val:
                root = root.right
            elif root.val > q.val:
                root = root.left
            else:
                return root