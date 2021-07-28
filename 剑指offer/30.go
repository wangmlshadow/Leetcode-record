type MinStack struct {
	nums []int
	minVal int
}


/** initialize your data structure here. */
func Constructor() MinStack {
    var minS MinStack
	minS.minVal = int(^uint(0) >> 1)
    return minS
}


func (this *MinStack) Push(x int)  {
	this.nums = append(this.nums, x)
	if this.minVal > x {
		this.minVal = x
	}
}


func (this *MinStack) Pop()  {
	res := this.nums[len(this.nums) - 1]
	this.nums = this.nums[:len(this.nums) - 1]
	if res == this.minVal {
		this.minVal = int(^uint(0) >> 1)
		for i := 0; i < len(this.nums); i++ {
			if this.minVal > this.nums[i] {
				this.minVal = this.nums[i]
			}
		}
	}
}


func (this *MinStack) Top() int {
	return this.nums[len(this.nums) - 1]
}


func (this *MinStack) Min() int {
	return this.minVal
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Min();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：28 ms, 在所有 Go 提交中击败了10.92%的用户
内存消耗：8.1 MB, 在所有 Go 提交中击败了32.18%的用户
*/