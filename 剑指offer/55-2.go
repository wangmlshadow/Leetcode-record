/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isBalanced(root *TreeNode) bool {
    result := true
	tra(root, &result)
	return result
}

func tra(root *TreeNode, result *bool) int {
	if *result == false {
		return 0
	}
	if root == nil {
		return 0
	}

	left, right := tra(root.Left, result), tra(root.Right, result)
	if left - right > 1 || right - left > 1 {
		*result = false
	}
	
	return 1 + max(left, right)
}

func max(left, right int) int {
	if left > right {
		return left
	}
	return right
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了95.90%的用户
内存消耗：5.8 MB, 在所有 Go 提交中击败了34.26%的用户
通过测试用例：227 / 227
*/