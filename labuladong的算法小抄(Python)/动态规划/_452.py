# -*- coding: utf-8 -*-
"""
Created on Tue Sep 29 20:31:07 2020

@author: Administrator
"""

"""
用最少数量的箭射爆气球

在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结
束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始
坐标总是小于结束坐标。平面内最多存在104个气球。

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开
始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出
的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部
被引爆，所需的弓箭的最小数量。
"""

from typing import List

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # 与区间调度一样 只需要寻找到最多的不重叠的子区间
        # 但是气球边沿碰到也会爆炸
        if len(points) == 0:
            return 0
        points = sorted(points, key = (lambda x:x[1]))
        count = 1
        xEnd = points[0][1]
        for point in points:
            start = point[0]
            if start > xEnd:# 边缘碰到也会爆炸
                count = count + 1
                xEnd = point[1]
        return count

"""
执行结果：通过 显示详情
执行用时：656 ms, 在所有 Python3 提交中击败了6.85%的用户
内存消耗：18.4 MB, 在所有 Python3 提交中击败了78.56%的用户
"""