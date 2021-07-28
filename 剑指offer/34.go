/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, target int) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}
    path := []int{}
	addPath(&res, path, root, target)
	return res
}

func addPath(res *[][]int, path []int, root *TreeNode, target int) {
	if root.Val == target && root.Left == nil && root.Right == nil {
		newPath := make([]int, len(path))
		copy(newPath, path)
		newPath = append(newPath, root.Val)
		*res = append(*res, newPath)
        fmt.Println(newPath)
		return
	}

	target = target - root.Val
	newPath := make([]int, len(path))
	copy(newPath, path)
	newPath = append(newPath, root.Val)
	
	if root.Left != nil {
		addPath(res, newPath, root.Left, target)
	}
	if root.Right != nil {
		addPath(res, newPath, root.Right, target)
	}
}
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 Go 提交中击败了16.87%的用户
内存消耗：13 MB, 在所有 Go 提交中击败了5.11%的用户
*/

func pathSum(root *TreeNode, target int) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}
    path := []int{}
	addPath(&res, &path, root, target)
	return res
}

func addPath(res *[][]int, pPath *[]int, root *TreeNode, target int) {
	if root.Val == target && root.Left == nil && root.Right == nil {
		newPath := make([]int, len(*pPath))
		copy(newPath, *pPath)
		newPath = append(newPath, root.Val)
		*res = append(*res, newPath)
		return
	}

	target = target - root.Val
	*pPath = append(*pPath, root.Val)
	
	if root.Left != nil {
		addPath(res, pPath, root.Left, target)
	}
	if root.Right != nil {
		addPath(res, pPath, root.Right, target)
	}

	*pPath = (*pPath)[:len(*pPath) - 1]
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了89.47%的用户
内存消耗：4.4 MB, 在所有 Go 提交中击败了72.60%的用户
*/