func spiralOrder(matrix [][]int) []int {
	res := make([]int)
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return res
	}
	left_row, left_clo, right_row, right_clo := 0, 0, len(matrix) - 1, len(matrix[0]) - 1
	for left_row <= right_row && left_clo <= right_clo {
		for i := left_clo; i <= right_clo; i++ {
			append(res, matrix[left_row][i])
		}
		for i := left_row + 1; i <= right_row; i++ {
			append(res, matrix[i][right_clo])
		}
		for i := right_clo - 1; left_row < right_row && i >= left_clo; i-- {
			append(res, matrix[right_row][i])
		}
		for i := right_row - 1; left_clo < right_clo && i > left_row; i-- {
			append(res, matrix[i][left_clo])
		}
		left_row++
		left_clo++
		right_row--
		right_clo--
	}
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 Go 提交中击败了82.92%的用户
内存消耗：6.5 MB, 在所有 Go 提交中击败了53.17%的用户
*/