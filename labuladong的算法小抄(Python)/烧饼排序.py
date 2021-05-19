# 烧饼排序
# 假设盘子上有 n 块面积大小不一的烧饼 你如何用一把锅铲进行若干次翻转 让这些烧饼大小有序
# 如何使用算法得到一个反转序列 使得烧饼堆变得有序

# 第969题
"""
给你一个整数数组 arr ，请使用 煎饼翻转 完成对数组的排序。

一次煎饼翻转的执行过程如下：

选择一个整数 k ，1 <= k <= arr.length
反转子数组 arr[0...k-1]（下标从 0 开始）
例如，arr = [3,2,1,4] ，选择 k = 3 进行一次煎饼翻转，反转子数组 [3,2,1] ，得到 arr = [1,2,3,4] 。

以数组形式返回能使 arr 有序的煎饼翻转操作所对应的 k 值序列。任何将数组排序且翻转次数在 10 * arr.length 范围内的有效答案都将被判断为正确。
"""

# 每次将最大的饼翻到最下面
# 先找到最大饼的位置 将它和它上面的都翻转 使得到达第一位 然后翻转 1-n 使其变成最下面的
# 然后依次 操作其余 n - 1块饼 不断循环

class Solution:
    def __init__(self):
        self.res = list()
        
    def pancakeSort(self, arr: List[int]) -> List[int]:
        #print(arr)
        self.sort(arr, len(arr))
        #print(arr)
        return self.res
    
    def sort(self, arr: List[int], n: int):
        # base case
        if n == 1:
            return
        
        # 寻找最大饼的索引
        maxCake, maxCakeIndex = 0, 0
        for i in range(n):
            if arr[i] > maxCake:
                maxCake = arr[i]
                maxCakeIndex = i
        
        # 第一次翻转 将最大饼翻到最上面
        self.reverse(arr, 0, maxCakeIndex)
        self.res.append(maxCakeIndex + 1)
        # 第二次翻转 将最大饼翻转到最下面
        self.reverse(arr, 0, n - 1)
        self.res.append(n - 1 + 1)
        
        # 递归调用
        self.sort(arr, n - 1)
        
    def reverse(self, arr: List[int], i: int, j: int):
        #print(arr)
        while i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1
        #print(arr)
"""
执行结果：通过
显示详情
执行用时：48 ms, 在所有 Python3 提交中击败了50.00%的用户
内存消耗：14.8 MB, 在所有 Python3 提交中击败了74.80%的用户
"""
