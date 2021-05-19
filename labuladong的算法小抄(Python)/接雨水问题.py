# 第42
# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
# 每个位子所能接的雨水 = min(左边最高的柱子，右边最高的柱子) - 此位置柱子高度

# 暴力解法：依次找到每个柱子左边最高的柱子 右边最高的柱子 然后求解所有位置能接的雨水和

# 备忘录优化 存储每个位置左边右边最高柱子的高度

# 双指针解法 边走边计算 不需要额外存储

# 备忘录
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        n = len(height)
        ans = 0
        # 备忘录
        leftMax = [0 for _ in range(n)]
        rightMax = [0 for _ in range(n)]
        # 初始化base case
        leftMax[0] = height[0]
        rightMax[n - 1] = height[n - 1]
        # 向左向右计算
        for i in range(1, n):
            leftMax[i] = max(height[i], leftMax[i - 1])
        for i in range(n - 2, -1, -1):
            rightMax[i] = max(height[i], rightMax[i + 1])
        # 计算答案
        for i in range(1, n - 1):
            ans += min(leftMax[i], rightMax[i]) - height[i]
        return ans
"""
执行结果：通过 显示详情 添加备注
执行用时：52 ms, 在所有 Python3 提交中击败了47.69%的用户
内存消耗：15.4 MB, 在所有 Python3 提交中击败了9.01%的用户
"""

# 双指针
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0
        n = len(height)
        left, right = 0, n - 1
        ans = 0
        # l_max 0...left 所有柱子的最高柱子高度
        # r_max right...n - 1 所有柱子的最高柱子高度
        l_max, r_max = height[0], height[n - 1]
        
        while left <= right:
            l_max = max(l_max, height[left])
            r_max = max(r_max, height[right])
            
            if l_max < r_max:
                ans += l_max - height[left]
                left += 1
            else:
                ans += r_max - height[right]
                right -= 1
        return ans
"""
执行结果：通过 显示详情 添加备注
执行用时：48 ms, 在所有 Python3 提交中击败了67.00%的用户
内存消耗：15 MB, 在所有 Python3 提交中击败了78.24%的用户
"""
