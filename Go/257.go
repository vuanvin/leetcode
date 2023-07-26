package leetcode

import "strconv"

var ans257 []string

func binaryTreePaths(root *TreeNode) []string {
	ans257 = []string{}
	constructPaths(root, "")
	return ans257
}

func constructPaths(root *TreeNode, path string) {
	if root != nil {
		pathSB := path
		pathSB += strconv.Itoa(root.Val)
		if root.Left == nil && root.Right == nil {
			ans257 = append(ans257, pathSB)
		} else {
			pathSB += "->"
			constructPaths(root.Left, pathSB)
			constructPaths(root.Right, pathSB)
		}
	}
}
