/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    var res *Node
	if head == nil {
		return res
	}

	rowMap := make(map[*Node]int, 0)
	resMap := make(map[int]*Node, 0)
	cnt := 0

	res = &Node{head.Val, nil, nil}
	rowMap[head] = cnt
	resMap[cnt] = res
	cnt++

	curRow := head.Next
	curRes := res

	for curRow != nil {
		curRes.Next = &Node{curRow.Val, nil, nil}
		curRes = curRes.Next
		rowMap[curRow] = cnt
		resMap[cnt] = curRes
		cnt++
		curRow = curRow.Next
	}

	curRow = head
	curRes = res

	for curRow != nil {
		if curRow.Random != nil {
			curRes.Random = resMap[rowMap[curRow.Random]]
		}
		curRow = curRow.Next
		curRes = curRes.Next
	}
	return res
}

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：3.6 MB, 在所有 Go 提交中击败了6.92%的用户
*/