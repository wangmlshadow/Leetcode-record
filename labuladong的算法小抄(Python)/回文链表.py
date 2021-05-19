# 第234
"""
请判断一个链表是否为回文链表。
"""
# 使用二叉树遍历框架以及双指针技巧实现单链表是否回文的判断
# 使用快慢指针寻找链表中点，并反转后半部分链表 再比较是否为回文
# 复制出来再判断

class Solution:
    def __init__(self):
        # 左侧指针
        self.left = None
        
    def isPalindrome(self, head: ListNode) -> bool:
        self.left = head
        return self.traverse(head)
    
    def traverse(self, right: ListNode) -> bool:
        if right is None:
            return True
        res = self.traverse(right.next)
        # 后序遍历代码
        res = res and (right.val == self.left.val)
        self.left = self.left.next
        return res
"""
执行结果：通过 显示详情 添加备注
执行用时：1252 ms, 在所有 Python3 提交中击败了5.08%的用户
内存消耗：115.3 MB, 在所有 Python3 提交中击败了6.22%的用户
"""
