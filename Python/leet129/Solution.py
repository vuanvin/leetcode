# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from leetcode.TreeNode import TreeNode


class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        if root == None:
            return 0
        self.view(root, 0)
        return self.res

    def view(self, root, val):
        if root.left == None and root.right == None:
            self.res += val * 10 + root.val
        if root.left:
            self.view(root.left, val * 10 + root.val)
        if root.right:
            self.view(root.right, val * 10 + root.val)