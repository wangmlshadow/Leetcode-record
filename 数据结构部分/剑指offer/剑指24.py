"""
剑指 24 反转链表
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
"""


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:# 防止head指向空链表
            return head
        if not head.next:
            return head
        last = self.reverseList(head.next)# 返回反转后的头节点
        head.next.next = head# 反转
        head.next = None
        return last
