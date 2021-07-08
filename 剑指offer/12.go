func exist(board [][]byte, word string) bool {
	if len(word) == 0 {
		return true
	}
	if len(board) == 0 || len(board[0]) == 0 {
		return false
	}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] == word[0] {
				ch := board[i][j]
				board[i][j] = '#'
				if existHead(board, i, j, word, 1) {
					return true
				}
				board[i][j] = ch
			}
		}
	}
	return false
}

func existHead(board [][]byte, row int, clo int, word string, pos int) bool {
	if pos >= len(word) {
		return true
	}

	if row - 1 >= 0 && row - 1 < len(board) && board[row - 1][clo] == word[pos] {
		ch := board[row - 1][clo]
		board[row - 1][clo] = '#'
		if existHead(board, row - 1, clo, word, pos + 1) {
			return true
		}
		board[row - 1][clo] = ch
	}
	if row + 1 >= 0 && row + 1 < len(board) && board[row + 1][clo] == word[pos] {
		ch := board[row + 1][clo]
		board[row + 1][clo] = '#'
		if existHead(board, row + 1, clo, word, pos + 1) {
			return true
		}
		board[row + 1][clo] = ch
	}
	if clo - 1 >= 0 && clo - 1 < len(board[0]) && board[row][clo - 1] == word[pos] {
		ch := board[row][clo - 1]
		board[row][clo - 1] = '#'
		if existHead(board, row, clo - 1, word, pos + 1) {
			return true
		}
		board[row][clo - 1] = ch
	}
	if clo + 1 >= 0 && clo + 1 < len(board[0]) && board[row][clo + 1] == word[pos] {
		ch := board[row][clo + 1]
		board[row][clo + 1] = '#'
		if existHead(board, row, clo + 1, word, pos + 1) {
			return true
		}
		board[row][clo + 1] = ch
	}
	return false
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了95.67%的用户
内存消耗：3.3 MB, 在所有 Go 提交中击败了98.32%的用户
*/