# -*- coding: utf-8 -*-
"""
Created on Tue Sep 22 16:19:28 2020

@author: Administrator
"""

"""
高楼扔鸡蛋 动态规划

你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。

每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。

你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。

每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。

你的目标是确切地知道 F 的值是多少。

无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
"""
"""
当一个鸡蛋从第i层楼丢下时，有两种结果：
    1.鸡蛋碎了 此时鸡蛋数为k-1，接下来要使用k-1个鸡蛋仔i-1层楼中继续测试
    2.鸡蛋没碎，此时鸡蛋数仍为k，并在i + 1...n层楼测试
"""
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        memo = dict()
        # dp[K][N] = m表示当前状态下有K个鸡蛋，面对N层楼，此状态下最少的扔鸡蛋次数为m
        def dp(K, N) -> int:
            # base case
            if K == 1: return N# 仅剩下一个鸡蛋时只能一个一个楼层实验
            if N == 0: return 0# 楼层为0时 不需要尝试 返回0
            
            if (K, N) in memo:
                return memo[(K, N)]
            
            res = float('INF')
            # 穷举所有可能性
            for i in range(1, N + 1):
                res = min(res, max(dp(K, N - i), dp(K - 1, i - 1)) + 1)
            memo[(K, N)] = res
            return res
            
        return dp(K, N)# 超时了 用了备忘录还是超时 后面需要用dp table
    

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        # 使用二分法优化
        # 二分搜索寻找dp(K - 1, i - 1)和dp(K, N - i)的交点
        # 固定 K N
        # dp(K - 1, i - 1)随着i的增加而增加
        # dp(K, N - i)随着i的增加而减小
        memo = dict()
        def dp(K, N) -> int:
            if K == 1: return N
            if N == 0: return 0
            if (K, N) in memo:
                return memo[(K, N)]
            
            res = float('INF')
            lo, hi = 1, N
            while lo <= hi:# 二分搜索寻找dp(K - 1, i - 1)和dp(K, N - i)的交点
                mid = (lo + hi) // 2
                broken = dp(K - 1, mid - 1)# 碎
                notBroken = dp(K, N - mid) # 没碎
                
                if broken > notBroken:# 交点在mid左边
                    hi = mid - 1
                    res = min(res, broken + 1)
                else:# 交点在mid右边
                    lo = mid + 1
                    res = min(res, notBroken + 1)
            
            memo[(K, N)] = res
            return res
        return dp(K, N)
"""
执行结果：通过 显示详情
执行用时：3176 ms, 在所有 Python3 提交中击败了14.84%的用户
内存消耗：44 MB, 在所有 Python3 提交中击败了16.39%的用户
"""

class Solution:
    def superEggDrop(self, K: int, N: int) -> int:# 继续优化
        # 重新定义状态转移方程
        # dp[k][m] = n 
        # 表示当前状态下有k个鸡蛋 可以尝试扔m次鸡蛋
        # 此状态下，最坏情况下能最多确切测试一栋n层的楼
        
        # 最多不会超过N次线性扫描
        dp = [[0] * (N + 1) for _ in range(K + 1)]
        # base case
        # dp[0][...] = 0
        # dp[...][0] = 0
        # 即鸡蛋数为0或者尝试次数为0时 最多能次数的楼层高度为0
        m = 0
        while dp[K][m] < N:
            m = m + 1
            for k in range(1, K + 1):# 不论在哪一层扔鸡蛋 总楼层数等于 1 + 鸡蛋碎的楼层 + 鸡蛋没碎的楼层
                dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1
        return m
"""
执行结果：通过 显示详情
执行用时：56 ms, 在所有 Python3 提交中击败了83.69%的用户
内存消耗：19.5 MB, 在所有 Python3 提交中击败了72.36%的用户
"""         