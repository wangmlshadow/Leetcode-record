/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}

	queue := []*TreeNode{}
	queue = append(queue, root)

	for len(queue) != 0 {
		temp := []*TreeNode{}
		tempRes := []int{}
		for len(queue) != 0 {
			cur := queue[0]
			queue = queue[1:]
			tempRes = append(tempRes, cur.Val)

			if cur.Left != nil {
				temp = append(temp, cur.Left)
			}
			if cur.Right != nil {
				temp = append(temp, cur.Right)
			}
		}
		res = append(res, tempRes)
		queue = temp[:]
	}
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.8 MB, 在所有 Go 提交中击败了87.12%的用户
*/