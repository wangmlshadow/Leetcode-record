/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargest(root *TreeNode, k int) int {
	res := 0
	cnt := 1
	tra(root, &res, &cnt, k)
	return res
}

func tra(root *TreeNode, res *int, cnt *int, k int) {
	if root == nil || *cnt > k {
		return
	}

	tra(root.Right, res, cnt, k)

	if *cnt == k {
		*res = root.Val
		*cnt += 1
		return
	}

	*cnt += 1
	tra(root.Left, res, cnt, k)
}
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 Go 提交中击败了52.69%的用户
内存消耗：6.4 MB, 在所有 Go 提交中击败了46.56%的用户
通过测试用例：91 / 91
*/