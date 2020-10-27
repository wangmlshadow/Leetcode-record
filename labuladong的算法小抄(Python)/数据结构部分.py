# -*- coding: utf-8 -*-
"""
Created on Mon Oct 19 20:28:40 2020

@author: Administrator
"""

from typing import List

"""
数据结构：
归根究底其实就两种：数组、链表
其他的都是在这两种结构上提供不同的API调用而已

二叉树问题大部分可以通过：前序、中序、后序、层次遍历解决 最多再加上visited[]
"""

"""
124
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包
含一个节点，且不一定经过根节点。
"""

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ans = float('-inf')
        # 后序遍历问题
        def res(r: TreeNode) -> int:
            if r is None: return 0
            left = max(res(r.left), 0)
            right = max(res(r.right), 0)
            nonlocal ans
            ans = max(ans, left + right + r.val)
            return r.val + max(left, right)
        res(root)
        return ans
"""
执行结果：通过 显示详情
执行用时：80 ms, 在所有 Python3 提交中击败了99.83%的用户
内存消耗：20.8 MB, 在所有 Python3 提交中击败了6.85%的用户
"""    



"""
105
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。
"""

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def _buildTree(pS, pE, iS, iE):
            if pS > pE or iS > iE: return None
            root = TreeNode(preorder[pS])
            pos = inorder.index(preorder[pS])
            root.left = _buildTree( pS + 1, pS + pos - iS, iS, pos - 1)
            root.right = _buildTree(pS + pos - iS + 1, pE, pos + 1, iE)
            return root
        return _buildTree(0, len(preorder) - 1, 0, len(inorder) - 1)
"""
执行结果：通过 显示详情
执行用时：96 ms, 在所有 Python3 提交中击败了73.64%的用户
内存消耗：18 MB, 在所有 Python3 提交中击败了70.47%的用户
"""


"""
99
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。
"""
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # 其实就是中序遍历问题
        # 找到一个升序排列的数组中两个被交换了位置的数
        pre = None
        a, b = None, None# 被错误交换的两个节点
        def traverse(node: TreeNode):
            if node is None: return None
            traverse(node.left)
            nonlocal pre, a, b
            if (pre is not None and node.val < pre.val and a is None):
                a = pre# 找到a
                b = node
            if (a is not None and node.val < a.val):
                b = node# 找到b
            pre = node
            traverse(node.right)
        traverse(root)
        tmp = a.val
        a.val = b.val
        b.val = tmp

"""
执行结果：通过 显示详情
执行用时：84 ms, 在所有 Python3 提交中击败了91.81%的用户
内存消耗：13.9 MB, 在所有 Python3 提交中击败了5.74%的用户
"""































