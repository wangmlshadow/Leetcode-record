# -*- coding: utf-8 -*-
"""
Created on Fri Nov 13 09:54:39 2020

@author: Administrator
"""

"""
单调队列 解决滑动窗口问题
"""

"""
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

进阶：

你能在线性时间复杂度内解决此题吗？

"""

from typing import List

# 单调队列的实现
class MonotonicQueue:
    def __init__(self):
        self.data = []# list模拟双向队列
    def push(self, n: int):
        while self.data and self.data[-1] < n:# 在push之前删除前面所有比被插入元素小的元素
            self.data.pop()
        self.data.append(n)
    def maxVal(self):
        return self.data[0]
    def pop(self, n):
        if self.data and self.data[0] == n:
            self.data.pop(0)

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        window = MonotonicQueue()
        res = []
        for i in range(len(nums)):
            if i < k - 1:# 填满滑动窗口
                window.push(nums[i])
            else:# 滑动窗口向前移动
                window.push(nums[i])
                res.append(window.maxVal())
                window.pop(nums[i - k + 1])
        return res
"""
执行结果：通过 显示详情
执行用时：672 ms, 在所有 Python3 提交中击败了9.06%的用户
内存消耗：26.7 MB, 在所有 Python3 提交中击败了5.01%的用户
"""
        