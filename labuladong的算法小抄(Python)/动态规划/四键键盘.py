# -*- coding: utf-8 -*-
"""
Created on Fri Oct  9 19:01:39 2020

@author: Administrator
"""

"""
四键键盘
假设你有一个特殊的键盘包含下面的键：
Key 1: (A): 在屏幕上打印一个'A'
Key 2: (Ctrl-A): 选中整个屏幕
Key 3: (Ctrl-C): 复制选中区域到缓冲区
Key 1: (Ctrl-V): 将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上
现在你可以按键N次，使用上述四种键，请问屏幕上最多可以显示几个A

动态规划的状态转移
dp(n - 1, a_num + 1, copy)
解释：按一下A键，屏幕上增加一个字符，同时消耗一个操作数
dp(n - 1, a_num + copy, copy)
解释：按一下C-V粘贴 剪切板中的字符加入屏幕，同时消耗一个操作数
dp(n - 2, a_num, a_num)
解释：全选和复制一起使用，剪切板中的A变成屏幕上A的数量，同时消耗两个操作数
"""

def maxA(N: int) -> int:
    # 对于(n, a_num, copy)这个状态
    # 屏幕上能最终最多能用dp(n, a_num, copy)个A
    # n表示操作数的数量 a_num表示屏幕上A的数量 copy表示缓冲区中A的数量
    def dp(n, a_num, copy):
        # base case
        if n <= 0: return a_num
        # 几种选择全试一遍 选择最大结果
        return max(dp(n - 1, a_num + 1, copy), dp(n - 1, a_num + copy, copy), dp(n - 2, a_num, a_num))
    # 可以按N次按键 屏幕和剪切板里都还没有A
    return dp(N, 0, 0)


def maxA(N: int) -> int:
    # 备忘录
    memo = dict()
    def dp(n, a_num, copy):
        # base case
        if n <= 0: return a_num
        # 避免重复计算
        if (n, a_num, copy) in memo: return memo[(n, a_num, copy)]
        memo[(n, a_num, copy)] =  max(dp(n - 1, a_num + 1, copy), dp(n - 1, a_num + copy, copy), dp(n - 2, a_num, a_num))
        return memo[(n, a_num, copy)]
    # 可以按N次按键 屏幕和剪切板里都还没有A
    return dp(N, 0, 0)

# 对上述状态进行求解即使使用备忘录 也任然很复杂 从三个参数可以看出复杂度至少为 N^3 下面考虑换一种思路
    


def maxA(N: int) -> int:
    # 定义: dp[i]表示i次操作后最多能显示多少个A
    dp = [0 for i in range(N + 1)]
    for i in range(1, N + 1):
        # 按A键
        dp[i] = dp[i - 1] + 1
        for j in range(2, i, 1):
            # 全选 复制 dp[j - 2] 再连续粘贴 i - j 次
            # 屏幕上共有 (i - j + 1) * dp[j - 2]个A
            dp[i] = max(dp[i], dp[j - 2] * (i - j + 1))
    return dp[N]
            






























