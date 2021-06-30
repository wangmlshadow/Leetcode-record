// 暴力循环
func findNumberIn2DArray(matrix [][]int, target int) bool {
	for _, row := range matrix {
		for _, num := range row {
			if num == target {
				return true
			}
		}
	}
	return false
}
/*
执行结果：通过 显示详情 添加备注
执行用时：32 ms, 在所有 Go 提交中击败了60.54%的用户
内存消耗：6.7 MB, 在所有 Go 提交中击败了49.04%的用户
*/

// 右上到左下
func findNumberIn2DArray(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	
	row, clo := 0, len(matrix[0]) - 1

	for row >= 0 && row < len(matrix) && clo >= 0 && clo < len(matrix[0]) {
		if matrix[row][clo] > target {
			clo -= 1
		} else if matrix[row][clo] < target {
			row += 1
		} else {
			return true
		}
	}

	return false
}
/*
执行结果：通过 显示详情 添加备注
执行用时：32 ms, 在所有 Go 提交中击败了60.54%的用户
内存消耗：6.7 MB, 在所有 Go 提交中击败了49.04%的用户
*/