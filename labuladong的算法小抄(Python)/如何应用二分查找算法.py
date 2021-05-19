# 第875
"""
珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
"""

# 每小时最多吃一堆香蕉 但如果香蕉多的话 一堆香蕉可能花费不止一小时
# 求解 h 小时吃完香蕉的最小速度 
# 不考虑速度 吃完所有香蕉最快为 香蕉的堆数小时 最慢为速度为1的时候
# 暴力求解的话 只需要从 1 开始测试 直到速度满足时间条件

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # 使用二分搜索提高效率
        # 最小速度为1 最大速度保证每一堆最多需要1小时
        # 速度区间为 [1, getMax(piles) + 1)
        left, right = 1, self.getMax(piles) + 1
        while left < right:
            # 防止溢出
            mid = left + (right - left) // 2
            if self.canFinish(piles, mid, h):
                right = mid
            else:
                left = mid + 1
        return left
    
    # 判断速度为speed 时间为H 是否可以吃完
    def canFinish(self, piles: List[int], speed: int, H: int) -> bool:
        time = 0
        for n in piles:
            time += self.timeOf(n, speed)
        return time <= H
    
    # 速度为speed 吃完n跟香蕉 需要多长时间       
    def timeOf(self, n: int, speed: int) -> int:
        return (n // speed) + (1 if (n % speed > 0) else 0)
    
    # 获取最大堆的香蕉数
    def getMax(self, piles: List[int]) -> int:
        maxValue = 0
        for n in piles:
            maxValue = max(n, maxValue)
        return maxValue
"""
执行结果：通过 显示详情 添加备注
执行用时：688 ms, 在所有 Python3 提交中击败了6.21%的用户
内存消耗：15.7 MB, 在所有 Python3 提交中击败了78.56%的用户
"""

# 第1011
"""
传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。

传送带上的第 i 个包裹的重量为 weights[i]。每一天，我们都会按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。

返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。
"""

class Solution:
    # 寻找左侧边界的二分查找
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        # 载重可能的最小值与最大值
        # 载重最小值 最重的包裹重量 
        # 载重最大值 所有包裹的总重量 即一船全部运走
        left, right = max(weights), sum(weights) + 1
        while left < right:
            mid = left + (right - left) // 2
            if self.canFinish(weights, D, mid):
                right = mid
            else:
                left = mid + 1
        return left
    
    # 如果载重未cap 是否可以在D天内运完货物
    def canFinish(self, w: List[int], D: int, cap: int) -> bool:
        i = 0
        for day in range(D):
            maxCap = cap
            while maxCap >= w[i]:
                maxCap -= w[i]
                i += 1
                if i == len(w):
                    return True
        return False
"""
执行结果：通过 显示详情 添加备注
执行用时：636 ms, 在所有 Python3 提交中击败了17.18%的用户
内存消耗：16.6 MB, 在所有 Python3 提交中击败了98.76%的用户
"""
