/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    allNodes := make(map[*ListNode]bool)

	for headA != nil && headB != nil {
		if _, ok := allNodes[headA]; !ok {
			allNodes[headA] = true
		} else {
			return headA
		}
		headA = headA.Next

		if _, ok := allNodes[headB]; !ok {
			allNodes[headB] = true
		} else {
			return headB
		}
		headB = headB.Next
	}

	for headA != nil {
		if _, ok := allNodes[headA]; !ok {
			allNodes[headA] = true
		} else {
			return headA
		}
		headA = headA.Next
	}

	for headB != nil {
		if _, ok := allNodes[headB]; !ok {
			allNodes[headB] = true
		} else {
			return headB
		}
		headB = headB.Next
	}

	return nil
}
/*
执行结果：通过 显示详情 添加备注
执行用时：36 ms, 在所有 Go 提交中击败了72.29%的用户
内存消耗：7.4 MB, 在所有 Go 提交中击败了94.17%的用户
通过测试用例：45 / 45
*/