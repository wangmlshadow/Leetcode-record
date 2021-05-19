# 当两个非常大的数相乘 最后结果会造成溢出 不能使用语言提供的数据结构存储时 一种替代的方法是使用字符串

# 第43题 字符串相乘
# 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

# 使用算法模拟两数相乘的具体过程
# 整个计算过程可以理解为 有两个指针 i, j 在 num1，num2 上游走，计算乘积，同时将乘积叠加到res的正确位置
# 再进一步
# num1[i] num2[j] 乘积对应的是res[i+j] res[i+j+1] 这两个位置
# i j 从 0 开始
# 30 * 40
# i = 1 j = 1 num[i] = 3 num[j] = 4
# 结果 res[i + j] = 2 res[i + j + 1] = 1
# 30 * 40 = 1200
# 可以这样想 num1[i] num2[j]实际代表的是 两个位置的数相乘再加上 i + j 个0

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        m, n = len(num1), len(num2)
        print(f'm = {m}, n = {n}')
        # 结果最多为 m + n 位数
        res = [0 for _ in range(m + n)]
        # 从个位数开始逐位相乘
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                print(f'i = {i}, j = {j}')
                mul = int(num1[i]) * int(num2[j])
                print(f'mul = {mul}')
                # 乘积在 res 对应的索引位置
                p1, p2 = i + j, i + j + 1
                # 叠加到res中
                print(f'res[p1] = {res[p1]}, res[p2] = {res[p2]}')
                sumValue = mul + res[p2]              
                print(f'sumValue = {sumValue}')
                res[p2] = sumValue % 10
                # 这里有问题 当res[p1]不为0时
                # 需要做成两个字符串相加的形式  
                toAdd = sumValue // 10
                while toAdd != 0 and p1 >= 0:
                    toAdd = toAdd + res[p1]
                    res[p1] = toAdd % 10
                    toAdd = toAdd // 10
                    p1 -= 1
                print(res)
        print(res)
        # 结果前缀可能存在0 未使用的位
        cnt = -1
        for i, value in enumerate(res):
            if value != 0:
                break
            cnt = i
        # 将结果转化为字符串
        res = res[cnt + 1:]
        if len(res) == 0:
            return "0"
        resStr = ''
        for n in res:
            resStr += str(n)
        return resStr
"""
执行结果：通过
显示详情
执行用时：192 ms, 在所有 Python3 提交中击败了32.61%的用户
内存消耗：15 MB, 在所有 Python3 提交中击败了26.46%的用户
"""
