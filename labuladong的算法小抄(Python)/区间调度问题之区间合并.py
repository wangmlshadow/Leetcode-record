# 第56题
# 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
# 先按start给数组排序
# 然后就简单了

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        # 按区间的start升序排列
        intervals.sort(key=lambda intv: intv[0])
        res = []
        res.append(intervals[0])
        
        for i in range(1, len(intervals)):
            curr = intervals[i]
            # res最后一个元素的引用
            last = res[-1]
            if curr[0] <= last[1]:
                # 找到最大的end
                last[1] = max(last[1], curr[1])
            else:
                # 处理下一个区间合并
                res.append(curr)
        return res
"""
执行结果：通过
显示详情
执行用时：52 ms, 在所有 Python3 提交中击败了48.42%的用户
内存消耗：15.6 MB, 在所有 Python3 提交中击败了25.98%的用户
"""
