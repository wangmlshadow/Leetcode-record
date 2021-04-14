# 八皇后问题 面试题0812
class Solution:
    def __init__(self):
        self.res = []
    
    def solveNQueens(self, n: int) -> List[List[str]]:
        # '.'表示空 'Q'表示皇后
        board = [['.' for i in range(n)] for j in range(n)]
        # 从第0行开始尝试 放置Q
        self.backtrack(board, 0)
        return self.res
    
    # 路径：board中小于row的那些行都已经成功放置了皇后
    # 选择列表：第row行的所有列都是放置皇后的选择
    # 结束条件：row超过board的最后一行
    def backtrack(self, board: List[str], row: int):
        # 触发结束条件
        if row == len(board):
            temp = []
            for line in board:
                temp.append(''.join(line))
            self.res.append([i for i in temp])# 深拷贝
            return
        n = len(board)
        for col in range(n):
            # 排除不合法选择
            if not self.isValid(board, row, col):
                continue
            # 做选择
            board[row][col] = 'Q'
            # 进入下一行决策
            self.backtrack(board, row + 1)
            # 撤销选择
            board[row][col] = '.'
    
    # 是否可以在board[row][col]位置放置皇后
    def isValid(self, board: List[str], row: int, col: int) -> bool:
        n = len(board)
        # 检查列是否有皇后互相冲突
        for i in range(0, n):
            if board[i][col] == 'Q':
                return False
        # 检查右上方是否有冲突
        for i, j in zip(range(row - 1, -1, -1), range(col + 1, n)):
            if board[i][j] == 'Q':
                return False
        # 检查左上方是否有冲突
        for i, j in zip(range(row - 1, -1, -1), range(col - 1, -1, -1)):
            if board[i][j] == 'Q':
                return False
        return True

"""
执行结果：通过
显示详情
执行用时：124 ms, 在所有 Python3 提交中击败了25.74%的用户
内存消耗：15.4 MB, 在所有 Python3 提交中击败了36.71%的用户
"""
