# 第25
"""
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

"""

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head is None:
            return head
        # 区间[a,b)包含k个待反转元素
        a, b = head, head
        for i in range(k):
            # 不足k个不需要反转 base case
            if b is None:
                return head
            b = b.next
        # 反转前k个元素
        newHead = self.reverse(a, b)
        # 递归反转后 链表并连接起来
        a.next = self.reverseKGroup(b, k)
        return newHead
            
    # 反转区间[a,b)的元素 左闭右开区间
    def reverse(self, a: ListNode, b: ListNode) -> ListNode:
        pre, cur, nxt = None, a, a
        while cur != b:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        # 返回反转后的头节点
        return pre
"""
执行结果：通过 显示详情 添加备注
执行用时：48 ms, 在所有 Python3 提交中击败了87.41%的用户
内存消耗：15.6 MB, 在所有 Python3 提交中击败了42.53%的用户
"""
