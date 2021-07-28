func verifyPostorder(postorder []int) bool {
	return isTrue(postorder, 0, len(postorder) - 1)
}

func isTrue(postorder []int, left int, right int) bool {
	if left >= right {
		return true
	}

	child_r := right - 1
	for child_r >= left && postorder[right] < postorder[child_r] {
		child_r--
	}

	for i := left; i < child_r; i++ {
		if postorder[right] <= postorder[i] {
			return false
		}
	}

	return isTrue(postorder, left, child_r) && isTrue(postorder, child_r + 1, right - 1)
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Go 提交中击败了66.12%的用户
*/