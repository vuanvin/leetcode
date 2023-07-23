package leetcode

import "strconv"

var ans []string

func binaryTreePaths(root *TreeNode) []string {
	ans = []string{}
	constructPaths(root, "")
	return ans
}

func constructPaths(root *TreeNode, path string) {
	if root != nil {
		pathSB := path
		pathSB += strconv.Itoa(root.Val)
		if root.Left == nil && root.Right == nil {
			ans = append(ans, pathSB)
		} else {
			pathSB += "->"
			constructPaths(root.Left, pathSB)
			constructPaths(root.Right, pathSB)
		}
	}
}
