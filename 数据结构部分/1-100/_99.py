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
