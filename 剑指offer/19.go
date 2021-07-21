func isMatch(s string, p string) bool {
	res := false
	match(s, p, 0, 0, &res)
	return res
}

func match(s string, p string, sPos int, pPos int, pRes *bool) {
	if *pRes {
		return
	}
	if sPos >= len(s) && pPos >= len(p) {
		*pRes = true
		return
	}
	if pPos + 1 < len(p) && p[pPos + 1] == '*' {
		if sPos < len(s) && (s[sPos] == p[pPos] || p[pPos] == '.') {
			match(s, p, sPos + 1, pPos, pRes)
		}
		match(s, p, sPos, pPos + 2, pRes)
	}
	if (sPos < len(s) && pPos < len(p)) && (s[sPos] == p[pPos] || p[pPos] == '.') && (pPos + 1 >= len(p) || p[pPos + 1] != '*') {
		match(s, p, sPos + 1, pPos + 1, pRes)
	}
}
/*
执行结果：通过 显示详情 添加备注
执行用时：28 ms, 在所有 Go 提交中击败了7.48%的用户
内存消耗：2.2 MB, 在所有 Go 提交中击败了73.23%的用户
*/