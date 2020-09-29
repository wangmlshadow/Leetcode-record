# -*- coding: utf-8 -*-
"""
Created on Tue Sep 29 16:47:51 2020

@author: Administrator
"""

"""
贪心算法：
给定多个区间，计算出这些区间中最多有几个互不相交的区间[start, end]。
"""

from typing import List

class Solution:
    def intervalSchedule(self, intvs: List[List[int]]) -> int:
        """
        贪心算法步骤：
        1.从子区间集合中选取出最先结束的子区间，end最小。
        2.将区间集合中所有和刚才所选出的区间有交集的区间全部去除
        3.重复上述步骤，直至intvs为空
        """
        if len(intvs) == 0:
            return 0
        # 按照end升序排列
        intvs = sorted(intvs, key = (lambda x:x[1]))
        # 至少有一个区间不相交
        count = 1
        xEnd = intvs[0][1]
        
        for interval in intvs:
            start = interval[0]
            if start >= xEnd:
                count = count + 1
                xEnd = interval[1]
        return count
        

"""
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:
可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
"""  

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # 总区间数减去最多的互不相交的区间数 就是需要移除的区间数
        if len(intervals) == 0:
            return 0
        intervals = sorted(intervals, key = (lambda x:x[1]))
        count = 1
        xEnd = intervals[0][1]
        for inte in intervals:
            start = inte[0]
            if start >= xEnd:
                count = count + 1
                xEnd = inte[1]
        return len(intervals) - count

"""
执行结果：通过 显示详情
执行用时：88 ms, 在所有 Python3 提交中击败了85.88%的用户
内存消耗：16.5 MB, 在所有 Python3 提交中击败了59.25%的用户
"""


























      