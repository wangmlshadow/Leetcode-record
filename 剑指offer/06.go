/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reversePrint(head *ListNode) []int {
	res := make([]int, 0)
	cur := head
	for cur != nil {
		res = append(res, cur.Val)
		cur = cur.Next
	}
	length := len(res)
	for i := 0; i < length / 2; i++ {
		res[i], res[length - 1 - i] = res[length - 1 - i], res[i]
	}
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：3.1 MB, 在所有 Go 提交中击败了74.71%的用户
*/

func reversePrint(head *ListNode) []int {
	res := make([]int, 0)
	rTraverse(head, &res)
	return res
}

func rTraverse(cur *ListNode, pres *[]int) {
	if cur == nil {
		return
	}
	rTraverse(cur.Next, pres)
	*pres = append(*pres, cur.Val)
}
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 Go 提交中击败了60.84%的用户
内存消耗：4.6 MB, 在所有 Go 提交中击败了35.33%的用户
*/