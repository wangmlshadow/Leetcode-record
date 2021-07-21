func myPow(x float64, n int) float64 {
    var cnt int64
    cnt = int64(n)
    if n < 0 {
		cnt = -cnt
		x = 1 / x
	}
	resMap := make(map[int64]float64)
	resMap[0] = 1.0
	resMap[1] = x
	return getRes(resMap, cnt)
}

func getRes(resMap map[int64]float64, n int64) float64 {
	if n == 0 || n == 1 {
		return resMap[n]
	}
	if res, ok := resMap[n]; ok {
		return res
	}
	resMap[n] = getRes(resMap, n / 2) * getRes(resMap, n - n / 2)
	return resMap[n]
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.2 MB, 在所有 Go 提交中击败了9.20%的用户
*/