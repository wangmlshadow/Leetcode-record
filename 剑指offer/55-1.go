/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
	return tra(root)
}

func tra(root *TreeNode) int {
	if root == nil {
		return 0
	}
	
	return 1 + max(tra(root.Left), tra(root.Right))
}

func max(left, right int) int {
	if left > right {
		return left
	}
	return right
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了87.65%的用户
内存消耗：4.2 MB, 在所有 Go 提交中击败了89.62%的用户
通过测试用例：39 / 39
*/