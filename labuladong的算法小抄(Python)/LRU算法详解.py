# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 10:48:32 2020

@author: Administrator
"""

"""
LRU 最近最少使用
是一种常用的缓存淘汰算法 
其认为最近使用过的数据是有用的 因此长时间没用过的数据在内存满了的时候 就应该优先被淘汰

用来表示LRU算法的数据结构的特点：
    查找快 插入快 删除快 有顺序之分
    
    通过哈希表和双向链表实现
"""

class Node:# 链表节点
    def __init__(self, k: int, v: int):
        self.key = k
        self.val = v
        
class DoubleList:# 双向链表
    def __init__(self):
        pass
    
    # 在链表头部添加节点x 时间为O(1)
    def addFirst(self, x: Node):
        pass
    
    # 删除链表中的x节点 该节点x一定存在
    # 由于是双链表 且给定的是目标 Node 节点 时间O(1)
    def remove(self, x: Node):
        pass
    
    # 删除链表中最后一个节点 并返回该节点 时间O(1)
    def removeLast(self) -> Node:
        pass
    
    # 返回链表长度
    def size(self) -> int:
        pass 
    

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.map = dict()
        self.cache = DoubleList()
        
    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        # 存在
        val = self.map[key].key
        # 利用put将该数据提前
        self.put(key, val)
        return val
    
    def put(self, key: int, val: int):
        # 先把新节点弄出来
        x = Node(key, val)
        
        if key in self.map:
            # 删除旧的节点 新的插到头部
            self.cache.remove(self.map[key])
            self.cache.addFirst(x)
        else:
            if self.cap == self.cache.size():
                # 链表满了
                last = self.cache.removeLast()
                self.map.pop(last.key)
            # 直接添加到头部
            self.cache.addFirst(x)
            map[key] = x
    
    































    
    