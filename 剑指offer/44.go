func findNthDigit(n int) int {
	if n < 10 {
		return n
	}

	cnt, len, times, allTimes, num := 9, 2, 90, 90, 10

	for cnt < n {
		if cnt + len >= n {
            str := strconv.Itoa(num)
            str = str[n - cnt - 1:n - cnt]
            res, _ := strconv.Atoi(str)
			return res
		}
		cnt += len
		num++
		times--
		if times == 0 {
			len++
			allTimes *= 10
			times = allTimes
		}
	}

	return 0
}
/*
执行结果：通过 显示详情 添加备注

执行用时：940 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2 MB, 在所有 Go 提交中击败了5.15%的用户
*/

func findNthDigit(n int) int {
	if n < 10 {
		return n
	}

	cnt, len, allTimes, num := 9, 2, 90, 10

	for cnt < n {
		if n > cnt + len * allTimes {
			num += allTimes
			cnt += len * allTimes
			len++
			allTimes *= 10
		} else {
			temp1 := n - cnt
			temp2 := int(temp1 / len)
			temp3 := temp1 % len

			if temp3 == 0 {
				str := strconv.Itoa(num + temp2 - 1)
				str = str[len - 1:]
				res, _ := strconv.Atoi(str)
				return res
			} else {
				str := strconv.Itoa(num + temp2)
				str = str[temp3 - 1:temp3]
				res, _ := strconv.Atoi(str)
				return res
			}
		}
	}

	return 0
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：1.9 MB, 在所有 Go 提交中击败了5.88%的用户
*/