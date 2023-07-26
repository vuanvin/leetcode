package leetcode

type Node struct {
	Val      int
	Children []*Node
}

func view(root *Node, p *[]int) {
	if root == nil {
		return
	}
	for _, child := range root.Children {
		view(child, p)
	}
	*p = append(*p, root.Val)
}

func postorder(root *Node) []int {
	var ans []int
	view(root, &ans)
	return ans
}
