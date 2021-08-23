// 与C++版本实现思路一致 但是不再使用辅助数组 直接在源数组修改
func maxValue(grid [][]int) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}

	for i := 1; i < len(grid[0]); i++ {
		grid[0][i] = grid[0][i] + grid[0][i - 1]
	}

	for i := 1; i < len(grid); i++ {
		grid[i][0] = grid[i][0] + grid[i - 1][0]
	}

	for i := 1; i < len(grid); i++ {
		for j := 1; j < len(grid[0]); j++ {
			if grid[i - 1][j] > grid[i][j - 1] {
				grid[i][j] = grid[i][j] + grid[i - 1][j]
			} else {
				grid[i][j] = grid[i][j] + grid[i][j - 1]
			}
		}
	}

	return grid[len(grid) - 1][len(grid[0]) - 1]
}
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 Go 提交中击败了11.36%的用户
内存消耗：3.8 MB, 在所有 Go 提交中击败了100.00%的用户
*/