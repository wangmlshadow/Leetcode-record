func cuttingRope(n int) int {
	res := make([][]int, n + 1)
	for i := 0; i <= n; i++ {
		res[i] = make([]int, n + 1)
	}

	for i := 1; i <= n; i++ {
		res[i][1] = i
		res[i][i] = 1
	}

	for i := 2; i <= n; i++ {
		for j := 2; j < i; j++ {
			max := 0
			for k := 2; k < i; k++ {
				if res[i - k][j - 1] == 0 {
					break
				}
				if max < k * res[i - k][j - 1] {
					max = k * res[i - k][j - 1]
				}
			}
			res[i][j] = max
		}
	}
	
	result := 0
	for i := 2; i <= n; i++ {
		if result < res[n][i] {
			result = res[n][i]
		}
	}

	return result
}

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.5 MB, 在所有 Go 提交中击败了5.46%的用户
*/