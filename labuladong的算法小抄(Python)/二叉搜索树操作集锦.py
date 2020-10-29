# -*- coding: utf-8 -*-
"""
Created on Thu Oct 29 15:46:56 2020

@author: Administrator
"""


"""
明确一个节点要做的事 其他的交给框架

二叉搜索树 BST

"""

class TreeNode:
    def __init_(self, val = None):
        self.left = None
        self.right = None
        self.val = val
        
# 判断一个二叉搜索树的合法性
def isValidBST(root):
    return isValidBST(root, None, None)

def isValid(root, minNode, maxNode):
    if root is None: return True
    if not minNode is None and root.val <= minNode.val:
        return False
    if not maxNode is None and root.val >= maxNode.val:
        return False
    return isValid(root.left, min, root) and isValid(root.right, root, maxNode)

# 在BST中查找一个数是否存在
def isInBST(root, target):
    if root is None: return False
    if root.val == target: return True
    if root.val < target:
        return isInBST(root.right, target)
    if root.val > target:
        return isInBST(root.left, target)
    
# 在BST中插入一个不存在的数
def insertIntoBST(root, val):
    # 找到空位置插入新节点
    if root is None: return TreeNode(val)
    if root.val < val:
        root.right = insertIntoBST(root.right, val)
    if root.val > val:
        root.left = insertIntoBST(root.left, val)
    return root


# 在BST中删除一个数
def deleteNode(root, key):
    if root is None: return None
    if root.val == key:
        # 要被删除的节点子节点情况：
        # 1.左右节点都为空 叶子节点
        # 2.左节点或者右节点为空
        # 3.左右节点都不为空
        
        # 处理情况1、2
        if root.left is None: return root.right 
        if root.right is None: return root.left 
        
        # 处理情况3 寻找左子树最大节点 或右子树最小节点 此处为后者
        def getMin(node):
            while not node.left is None:
                node = node.left 
            return node
        
        minNode = getMin(root.right)
        root.val = minNode.val 
        root.right = deleteNode(root.right, minNode.val)
    elif root.val > key:
        root.left = deleteNode(root.left, key)
    else:
        root.right = deleteNode(root.right, key)
    return root
































