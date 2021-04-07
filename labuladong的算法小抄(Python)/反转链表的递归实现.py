# LeetCode 206 92 分别是反转整个链表和反转单链表的一部分
# 上述问题的迭代实现并不困难，但是递归实现呢
# 递归实现如下

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
# 反转整个单链表
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        last = self.reverse(head)
        head.next = None
        return last
    
    # 输入一个节点head 将以head为起点的链表反转 并返回反转之后的头节点
    def reverse(self, head: ListNode) -> ListNode:
        if head.next is None:
            return head
        last = self.reverse(head.next)# 通过last返回最后一个节点 也是反转后的第一个节点
        head.next.next = head# 反转 使得next.next指向自身
        return last
"""
执行结果：通过
显示详情
执行用时：44 ms, 在所有 Python3 提交中击败了63.41%的用户
内存消耗：19.6 MB, 在所有 Python3 提交中击败了21.61%的用户
"""

# 反转链表的前n的节点
# 注意此处序号从 1 开始
class Solution:
    def __init__(self):
        self.successor = None# 后驱节点
    
    def reverseN(self, head: ListNode, n: int) -> ListNode:
        if n == 1:
            # 记录第n+1个节点
            self.successor = head.next
            return head
        # 以head.next为起点 需要反转前 n-1 个节点
        last = self.reverseN(head.next, n - 1)
        head.next.next = head
        head.next = self.successor
        return last
      
# 反转从位置m到n的链表，使用一趟扫描实现
class Solution:
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if left == 1:
            return self.reverseN(head, right)
        # 前进到反转的起点触发 base case
        head.next = self.reverseBetween(head.next, left - 1, right - 1)
        return head
    
    def __init__(self):
        self.successor = None# 后驱节点
    
    def reverseN(self, head: ListNode, n: int) -> ListNode:
        if n == 1:
            # 记录第n+1个节点
            self.successor = head.next
            return head
        # 以head.next为起点 需要反转前 n-1 个节点
        last = self.reverseN(head.next, n - 1)
        head.next.next = head
        head.next = self.successor
        return last    

"""
执行结果：通过
显示详情
执行用时：48 ms, 在所有 Python3 提交中击败了15.77%的用户
内存消耗：15 MB, 在所有 Python3 提交中击败了51.99%的用户
"""

# 使用递归反转链表的效率比不上迭代
