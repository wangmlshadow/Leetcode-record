/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getKthFromEnd(head *ListNode, k int) *ListNode {
	first := head
	for k > 1 && first != nil {
		first = first.Next
		k--
	}
	if first == nil {
		return nil
	}
	second := head
	for first.Next != nil {
		first = first.Next
		second = second.Next
	}
	return second
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.2 MB, 在所有 Go 提交中击败了61.30%的用户
*/