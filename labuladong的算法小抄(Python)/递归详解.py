# 概念
# 几个问题：
# 结束条件与自我调用

# 考虑递归问题 要从整体出发 不要被细节绊住 要相信最后的递归结束条件以及递归函数可以自己解决子问题

# 第437
"""
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

"""


class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        if root is None:
            return 0
        # 自己为开头的路径数
        pathImLeading = self.count(root, targetSum)
        # 左子树路径总数
        leftPathSum = self.pathSum(root.left, targetSum)
        # 右子树
        rightPathSum = self.pathSum(root.right, targetSum)
        return pathImLeading + leftPathSum + rightPathSum
    
    def count(self, node: TreeNode, targetSum: int) -> int:
        if node is None:
            return 0
        # node节点值等于targetSum 单独一个节点就可以成为一条路径
        isMe = 1 if (node.val == targetSum) else 0
        # 左子树有几条和为 targetSum-node.val的路径
        leftBrother = self.count(node.left, targetSum - node.val)
        # 右子树
        rightBrother = self.count(node.right, targetSum - node.val)
        return isMe + leftBrother + rightBrother
"""
执行结果：通过 显示详情 添加备注
执行用时：980 ms, 在所有 Python3 提交中击败了6.06%的用户
内存消耗：15.9 MB, 在所有 Python3 提交中击败了78.96%的用户
"""
