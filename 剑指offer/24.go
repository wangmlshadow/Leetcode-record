/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	res := reverse(head)
	head.Next = nil
	return res
}

func reverse(head *ListNode) *ListNode {
	if head.Next == nil {
		return head
	}
	res := reverse(head.Next)
	head.Next.Next = head
	return res
}
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：3 MB, 在所有 Go 提交中击败了13.21%的用户
*/