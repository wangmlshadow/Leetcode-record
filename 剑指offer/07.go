/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	return build(preorder, inorder, 0, len(preorder) - 1, 0, len(inorder) - 1)
}

func build(preorder []int, inorder []int, pl int, pr int, il int, ir int) *TreeNode {
	if pl > pr {
		return nil
	}
	root := new(TreeNode)
	root.Val = preorder[pl]
	imid := il
	for i := il; i <= ir; i++ {
		if inorder[i] == preorder[pl] {
			imid = i
			break
		}
	}
	root.Left = build(preorder, inorder, pl + 1, pl + (imid - il), il, imid - 1)
	root.Right = build(preorder, inorder, pl + (imid - il + 1), pr, imid + 1, ir)
	return root
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败95.06%的用户
内存消耗：4.3 MB, 在所有 Go 提交中击败了19.49%的用户
*/