func validateStackSequences(pushed []int, popped []int) bool {
	if len(pushed) != len(popped) {
		return false
	}
	i, j := 0, 0
	var stack []int
	for i = 0; i < len(popped); i++ {
		if len(stack) != 0 {
			if stack[len(stack) - 1] == popped[i] {
				stack = stack[:len(stack) - 1]
				continue
			}
			if j >= len(pushed) {
				return false
			}
		}
		for j < len(pushed) && pushed[j] != popped[i] {
			stack = append(stack, pushed[j])
			j++
		}
		if j >= len(pushed) {
			return false
		}
		if j < len(pushed) {
			j++
		}
	}
	return true
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了98.18%的用户
内存消耗：3.8 MB, 在所有 Go 提交中击败了77.33%的用户
*/