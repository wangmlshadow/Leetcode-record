type MedianFinder struct {
	allNums []int
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{allNums: make([]int, 0)}
}

func (this *MedianFinder) AddNum(num int)  {
	var pos int
	for pos = 0; pos < len(this.allNums); pos++ {
		if num < this.allNums[pos] {
			break
		}
	}
	
	end := append([]int{}, this.allNums[pos:]...)
	this.allNums = append(this.allNums[:pos], num)
	this.allNums = append(this.allNums, end...)
}

func (this *MedianFinder) FindMedian() float64 {
	cnt := len(this.allNums)
	var res float64
	if cnt % 2 == 1 {
		res = float64(this.allNums[cnt / 2])
	} else {
		res = float64(this.allNums[cnt / 2 - 1] + this.allNums[cnt / 2]) / 2
	}
	return res

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：460 ms, 在所有 Go 提交中击败了11.79%的用户
内存消耗：23.2 MB, 在所有 Go 提交中击败了11.79%的用户
*/