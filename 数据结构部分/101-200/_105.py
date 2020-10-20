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
