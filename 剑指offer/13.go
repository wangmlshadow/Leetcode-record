func movingCount(m int, n int, k int) int {
	res := 0
	existed := make([][]bool, m)

	for i := 0; i < m; i++ {
		existed[i] = make([]bool, n)
	}
	
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			existed[i][j] = false
		}
	}

	toNext(0, 0, existed, &res, m, n, k)
	return res
}

func canArrive(row int, clo int, limit int) bool {
	sum := 0
	for row != 0 {
		sum += row % 10
		row /= 10
	}
	for clo != 0 {
		sum += clo % 10
		clo /= 10
	}
	return limit >= sum
}

func toNext(row int, clo int, existed [][]bool, pres *int, allRows int, allClos int, limit int) {
	if row < 0 || clo < 0 || row >= allRows || clo >= allClos {
		return
	}
	if existed[row][clo] {
		return
	}
	existed[row][clo] = true
	if !canArrive(row, clo, limit) {
		return
	}
	*pres++

	toNext(row - 1, clo, existed, pres, allRows, allClos, limit)
	toNext(row + 1, clo, existed, pres, allRows, allClos, limit)
	toNext(row, clo - 1, existed, pres, allRows, allClos, limit)
	toNext(row, clo + 1, existed, pres, allRows, allClos, limit)
}

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.6 MB, 在所有 Go 提交中击败了46.82%的用户
*/