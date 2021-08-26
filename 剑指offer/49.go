// 动态规划
func nthUglyNumber(n int) int {
	nums := make([]int, n + 1)
	p2, p3, p5 := 1, 1, 1
	nums[1] = 1

	for i := 2; i <= n; i++ {
		num2, num3, num5 := nums[p2] * 2, nums[p3] * 3, nums[p5] * 5
		nums[i] = min(min(num2, num3), num5)
		if nums[i] == num2 {
			p2++
		}
		if nums[i] == num3 {
			p3++
		}
		if nums[i] == num5 {
			p5++
		}
	}

	return nums[n]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了58.59%的用户
内存消耗：4.2 MB, 在所有 Go 提交中击败了49.22%的用户
*/