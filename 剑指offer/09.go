type CQueue struct {
    stack1, stack2 *list.List
}


func Constructor() CQueue {
	return CQueue{
        stack1: list.New(),
        stack2: list.New(),
    }
}


func (this *CQueue) AppendTail(value int)  {
	this.stack1.PushBack(value)
}


func (this *CQueue) DeleteHead() int {
	if this.stack1.Len() == 0 {
		return -1
	}
	for this.stack1.Len() != 0 {
		this.stack2.PushBack(this.stack1.Remove(this.stack1.Back()))
	}
	res := this.stack2.Back()
    this.stack2.Remove(res)
	for this.stack2.Len() != 0 {
		this.stack1.PushBack(this.stack2.Remove(this.stack2.Back()))
	}
    return res.Value.(int)
}

/**
 * Your CQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AppendTail(value);
 * param_2 := obj.DeleteHead();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：1284 ms, 在所有 Go 提交中击败了5.11%的用户
内存消耗：8.8 MB, 在所有 Go 提交中击败了5.02%的用户
 */