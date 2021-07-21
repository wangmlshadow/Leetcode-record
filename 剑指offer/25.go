/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	var head, cur *ListNode
	if l1.Val < l2.Val {
		head = l1
		cur = l1
		l1 = l1.Next
	} else {
		head = l2
		cur = l2
		l2 = l2.Next
	}

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			cur.Next = l1
			cur = l1
			l1 = l1.Next
		} else {
			cur.Next = l2
			cur = l2
			l2 = l2.Next
		}
	}

	for l1 != nil {
		cur.Next = l1
		cur = l1
		l1 = l1.Next
	}
	for l2 != nil {
		cur.Next = l2
		cur = l2
		l2= l2.Next
	}

	return head
}