/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if A == nil || B == nil {
		return false
	}
	res := false
	trav(A, B, &res)
	return res
}

func trav(A *TreeNode, B *TreeNode, pRes *bool) {
	if A == nil || *pRes {
		return
	}
	if isSub(A, B) {
		*pRes = true
		return
	}
	trav(A.Left, B, pRes)
	trav(A.Right, B, pRes)
}

func isSub(A *TreeNode, B *TreeNode) bool {
	if B == nil {
		return true
	}
	if B != nil && A == nil {
		return false
	}
	if A.Val != B.Val {
		return false
	}
	return isSub(A.Left, B.Left) && isSub(A.Right, B.Right)
}
/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 Go 提交中击败了94.57%的用户
内存消耗：7 MB, 在所有 Go 提交中击败了21.99%的用户
*/