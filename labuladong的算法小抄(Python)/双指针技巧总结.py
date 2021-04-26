# 双指针技巧分为两类：快慢指针 左右指针
# 快慢指针主要解决链表中的问题
# 左右指针主要解决数组中的问题

# 判定链表中是否有环
def hasCycle(head: ListNode) -> bool:
    while head != None:# 有环则一直循环
        head = head.next
    return false

# 使用快慢指针
def hasCycle(head: ListNode) -> bool:
    fast, slow = head, head
    while fase != None and fast.next != None:
        # fast每次走两步
        # slow每次走一步
        fast = fast.next.next
        slow = slow.next
        
        # 有环则fast与slow会相遇
        if fast == slow:
            return True
    # 不存在环 循环结束 返回False
    return False
  
# 已知链表中有环 返回环的起始位置
def detectCycle(head: ListNode) -> ListNode:
    fast, slow = head, head
    while fast != None and fast.next != None:
        fast = fast.next.next
        slow = slow.next
        if fast == slow:
            break
    slow = head
    while slow != fast:
        fast = fast.next
        slow = slow.next
    return slow
  
# 寻找链表的中点
while fast != None and fast.next != None:
    fast = fast.next.next
    slow = slow.next
return slow
# fast的速度是slow的两倍 fast到达终点 slow则在中点

# 寻找链表的第k个元素
# 让fast先走k步
slow, fast = head, head
while k > 0:
    k = k - 1
    fast = fast.next

while fast != None:
    slow = slow.next
    fast = fast.next

return slow


# 左右指针的常用算法
# 二分查找

# 两数之和
# 第167题
# 给定一个已按照升序排列的有序数组 找到两个数使得它们相加之和等于目标数
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers) - 1
        while left < right:
            sum = numbers[left] + numbers[right]
            if sum == target:
                return [left + 1, right + 1]
            elif sum < target:
                left = left + 1
            else:
                right = right - 1
        return [-1, -1]
    
"""
执行结果：通过
显示详情
执行用时：48 ms, 在所有 Python3 提交中击败了48.93%的用户
内存消耗：15.2 MB, 在所有 Python3 提交中击败了67.40%的用户
"""

# 反转数组
def reverse(nums: List[int]):
    left, right = 0, len(nums) - 1
    while left < right:
        nums[left], nums[right] = nums[right], nums[left]
        left += 1
        right -= 1
