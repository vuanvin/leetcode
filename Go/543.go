package leetcode

func diameterOfBinaryTree(root *TreeNode) int {
	ans := 0
	var dfs func(*TreeNode) int
	dfs = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ans = max(ans, l+r+1)
		return max(l, r) + 1
	}
	dfs(root)
	return ans - 1
}
