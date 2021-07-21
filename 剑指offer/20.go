func isNumber(s string) bool {
	if (len(s) <= 0) {
		return false
	}
	// 去空格
	left, right := 0, len(s) - 1
	for left = left; left < len(s); left++ {
		if s[left] != ' ' {
			break
		}
	}
	for right = right; right >= 0; right-- {
		if s[right] != ' ' {
			break
		}
	}
	if left > right {
		return false
	}
	// 正负号
	if s[left] == '+' || s[left] == '-' {
		if left == right {// 只有正负号
			return false
		}
		left++
	}
	// 数字
	leftNum := false// 小数点左边是否有数字
	for left <= right {
		if !unicode.IsDigit(rune(s[left])) {
			break
		}
		leftNum = true
		left++
	}
	if left > right {
		return true;
	}
	// 小数点
	rightNum := false// 小数点右边是否有数字
	if (s[left] == '.') {
		left++
		for left <= right {
			if !unicode.IsDigit(rune(s[left])) {
				break
			}
			rightNum = true
			left++
		}    
	}
	// 排除数值中没有小数 或者 整数的情况
	if !leftNum && !rightNum {
		return false;
	}
	if left > right {
		return true
	}
	if s[left] == 'E' || s[left] == 'e' {            
		if left == right {// 只有E
			return false
		}
		left++
		numFollowE := false;// E 后是否有整数
		if s[left] == '+' || s[left] == '-' {
			if left == right {// 只有正负号
				return false
			}
			left++
		}
		for left <= right {
			if !unicode.IsDigit(rune(s[left])) {
				break
			}
			numFollowE = true
			left++
		}
		if !numFollowE {// E 后无整数
			return false
		}
	}
	if left > right {
		return true
	}
	return false
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了67.05%的用户
内存消耗：2.3 MB, 在所有 Go 提交中击败了81.78%的用户
*/

func isNumber(s string) bool {
	if (len(s) <= 0) {
		return false
	}
	// 去空格
	left, right := 0, len(s) - 1
	for left = left; left < len(s); left++ {
		if s[left] != ' ' {
			break
		}
	}
	for right = right; right >= 0; right-- {
		if s[right] != ' ' {
			break
		}
	}
	if left > right {
		return false
	}
	_, err := strconv.ParseFloat(s[left:right + 1], 64)
	return err == nil
}