func reversePairs(nums []int) int {
	temp := make([]int, len(nums))
	return mergeSort(nums, temp, 0, len(nums) - 1)
}

func mergeSort(nums []int, temp []int, l int, r int) int {
	if l >= r {
		return 0
	}

	mid := (l + r) / 2
	inv_count := mergeSort(nums, temp, l, mid) + mergeSort(nums, temp, mid + 1, r)
	i, j, pos := l, mid + 1, l

	for i <= mid && j <= r {
		if nums[i] <= nums[j] {
			temp[pos] = nums[i]
			i++
			inv_count += j - (mid + 1)
		} else {
			temp[pos] = nums[j]
			j++
		}
		pos++
	}

	for k := i; k <= mid; k++ {
		temp[pos] = nums[k]
		pos++
		inv_count += j - (mid + 1)
	}

	for k := j; k <= r; k++ {
		temp[pos] = nums[k]
		pos++
	}

	copy(nums[l:r + 1], temp[l:r + 1])
	return inv_count
}
/*
执行结果：通过 显示详情 添加备注
执行用时：88 ms, 在所有 Go 提交中击败了94.71%的用户
内存消耗：7.6 MB, 在所有 Go 提交中击败了81.40%的用户
*/