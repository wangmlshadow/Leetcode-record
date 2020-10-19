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
