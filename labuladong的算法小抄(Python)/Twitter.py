# -*- coding: utf-8 -*-
"""
Created on Tue Nov 17 15:22:06 2020

@author: Administrator
"""

"""
设计Twitter
合并多个有序链表和面向对象程序设计
"""        
from typing import List
from queue import PriorityQueue

class Twitter:
    # 静态私有变量
    __timestamp = 0
    # userId User的映射
    userMap = dict()
    
    
    def __init__(self):
        pass
    
    def postTweet(self, userId: int, tweetId: int):
        # 如果userId不存在则新建
        if not self.userMap.has_key(userId):
            self.userMap[userId] = User()
        u = self.userMap[userId]
        u.post(tweetId)
                  
    def follow(self, followerId: int, followeeId: int):
        # 若follower不存在 则重建
        if not self.userMap.has_key(followerId):
            u = User(followerId)
            self.userMap[followerId] = u
        # 若followee不存在 则新建
        if not self.userMap.has_key(followeeId):
            u = User(followeeId)
            self.userMap[followeeId] = u
        self.userMap.get(followerId).follow(followeeId)
        
    # 取消关注
    def unfollow(self, followerId: int, followeeId: int):
        if self.userMap.has_key(followeeId):
            flwer = self.userMap[followerId]
            flwer.unfollow(followeeId)

    # 返回结果在时间上有序 动态变化的
    # 返回最近的十条动态
    def getNewsFeed(self, userId: int) -> List:
        # 合并k个有序链表
        # 使用优先级队列
        res = []
        if not self.userMap.has_key(userId):
            return res
        
        users = self.userMap.get(userId).followed
        # 通过time属性从大到小排序 容量为users的大小
        q = PriorityQueue()
        for id in users:
            twt = self.userMap[id].head
            if twt is None: continue
            q.put(-twt.__time, twt)
        while not q.empty():
            # 最多返回10条
            if len(res) == 10: break
            twt = q.get()
            res.append(twt.__id)
            # 将下一篇插入进行排序
            if twt.__next is not None:
                q.put(twt.__next)
        return res
        

class Tweet:
    def __init__(self, id: int, time: int):
        self.__id = id
        self.__time = time
        self.__next = None
    
class User:
    def __init__(self, userId: int):
        self.__id = userId
        self.followed = set()
        self.head = None
        
    def follow(self, userId: int):
        self.followed.add(userId)
        
    def unfollow(self, userId: int):
        # 不可以取关自己
        if userId != self.__id:
            self.followed.remove(userId)
            
    def post(self, tweetId: int):
        twt = Tweet(tweetId, Twitter.__timestamp)
        Twitter.__timestamp += 1
        # 将新建的推文插入链表头
        # 越靠前的推文time越大
        twt.__next = self.head
        self.head = twt

        