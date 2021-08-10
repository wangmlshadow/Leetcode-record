type StringSlice []string

func (s StringSlice) Len() int { return len(s) }
func (s StringSlice) Swap(i, j int) { s[i], s[j] = s[j], s[i] }
func (s StringSlice) Less(i, j int) bool { 
	return compare(s[i], s[j])
}


func minNumber(nums []int) string {
	res := ""

	if len(nums) == 0 {
		return res
	}

	ok := true
	for _, num := range nums {
		if num != 0 {
			ok = false
			break
		}
	}

	if ok == true {
		for i := 0; i < len(nums); i++ {
			res += "0"
		}
		return res
	}

	allNums := make([]string, len(nums))

	for i, _ := range allNums {
		allNums[i] = strconv.Itoa(nums[i])
	}

	sort.Sort(StringSlice(allNums))

	for _, num := range allNums {
		res += num
	}

	return res
}

func compare(a, b string) bool {
	left, right := 0, 0
	for left < len(a) && right < len(b) {
		if a[left] < b[right] {
			return true;
		} else if a[left] > b[right] {
			return false;
		} else {

		}
		left++;
		right++
	}

	if left < len(a) {
		return compare(a[left:], b)
	}

	if right < len(b) {
		return compare(a, b[right:])
	}

	return true
}

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.8 MB, 在所有 Go 提交中击败了43.10%的用户
*/