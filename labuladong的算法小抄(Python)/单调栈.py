# -*- coding: utf-8 -*-
"""
Created on Mon Nov  9 16:35:04 2020

@author: Administrator
"""

"""
单调栈
在栈的基础上，通过一些巧妙的逻辑，使得每次新元素入栈后，栈内元素都保持有序（单调递增或单调递减）

Next Greater Number：
    给定一个数组，返回一个等长数组，对应索引存储着下一个更大元素，如果没有更大元素就存-1.
"""

from typing import List

def nextGreaterElement(nums: List) -> List:
    cnt = len(nums)
    ans = [-1] * cnt
    s = []
    
    for i in range(cnt - 1, -1, -1):
        while s and s[-1] <= nums[i]:
            s.pop()
        ans[i] = s[-1] if s else -1
        s.append(nums[i])
    
    return ans

#n = [2, 1, 2, 4, 3]
#print(nextGreaterElement(n))


"""
循环数组
将上述next greater number换成循环数组

"""

class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        cnt = len(nums)
        res = [-1] * cnt
        s = []
        # 既要考虑后面的元素 也要考虑前面的元素
        # 假装数组长度翻倍了
        for i in range(2 * cnt - 1, -1, -1):
            while s and s[-1] <= nums[i % cnt]:
                s.pop()
            res[i % cnt] = s[-1] if s else -1
            s.append(nums[i % cnt])
        return res
"""
执行结果：通过显示详情
执行用时：316 ms, 在所有 Python3 提交中击败了26.60%的用户
内存消耗：15.1 MB, 在所有 Python3 提交中击败了24.78%的用户
"""































