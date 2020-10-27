# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 09:39:06 2020

@author: Administrator
"""

"""
二叉堆是一种特殊的二叉树（完全二叉树），它存储在数组中。

数组的第一个索引空着不用
parent = child / 2
leftChild = parent * 2
rightChild = parent * 2 + 1

二叉堆分为最大堆 最小堆
最大堆：每个节点都大于等于他的两个子节点
"""

"""
优先级队列
插入或删除元素时 元素会自动排序
"""
class Key:
    def compareTo(self, other: Key):
        pass 
    

class MaxPQ:# 大根堆->优先级队列
    def __init__(self, cap: int, key: Key):
        self.N = 0# 当前Priority Queue中的元素个数
        self.pq = [key] * (cap + 1)# 用于存储元素的数组 索引0不用 多分配一个空间
    
    def max(self):# 返回当前队列中最大元素
        return self.pq[1]
    
    def parent(root: int) -> int:# 父节点索引
        return root // 2
    
    def left(root: int) -> int:# 左孩子索引
        return root * 2
    
    def right(root: int) -> int:# 右孩子索引
        return root * 2 + 1
    
    def insert(self, e):# 插入元素e
        self.N += 1
        # 先把新元素加到最后
        self.pq[self.N] = e
        # 然后让它上浮到正确位置
        self.swim(self.N)
        
        
    def delMax(self):# 删除并返回当前队列中的对大元素
        # 最大堆的堆顶就是最大元素    
        maxVal = self.pq[1]
        # 把这个最大的元素换到最后 删除之
        self.exch(1, self.N)
        self.N -= 1
        # 让pq[1]下沉到合适位置
        self.sink(1)
        return maxVal
        
    
    def swim(self, k: int):# 上浮第k个元素 以维护最大堆性质
        # 如果浮到堆顶 就不能再上浮了
        while k > 1 and self.less(self.parent(k), k):
            # 如果第k个元素比上层大 将k换上去
            self.exch(self.parent(k), k)
            k = self.parent(k)
    
    def sink(self, k: int):# 下沉第k个元素 以维护最大堆性质
        # 如果沉到堆底 就沉不下去了
        while self.left(k) <= self.N:
            # 先假设左边节点较大
            older = self.left(k)
            # 如果右边节点存在 比一下大小
            if self.right(k) <= self.N and self.less(older, self.right(k)):
                older = self.right(k)
            # 节点比两孩子都大 就不必下沉了
            if self.less(older, k):
                break 
            # 否则不符合最大堆结构 下沉k节点
            self.exch(k, older)
            k = older
    
    def exch(self, i: int, j: int):# 交换数组两元素
        temp = self.pq[i]
        self.pq[i] = self.pq[j]
        self.pq[j] = temp
    
    def less(self, i: int, j: int):# 判断pq[i] 是否比 pa[j]小
        return self.pq[i].compareTo(self.pq[j])
    


























        