# 很多使用DFS的问题也可以使用Union-Find解决
# 第130
# 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
# Union-Find底层用的是一维数组 这里需要将二维数组映射到一维 
# 二维坐标(x, y) -> x*n + y

class UF:
    def __init__(self, n: int):# n 为图的结点总数
        # 记录连通分量
        self.count = n
        # 记录节点 x 的父节点 parent[x]
        # 初始状态下每个节点的父节点是他自身
        self.parent = [i for i in range(n)]
        # 记录树的重量 初始状态下每棵树只有一个节点
        self.size = [1 for i in range(n)]

    def find(self, x: int) -> int:
        # 根节点的父节点是它自身
        while self.parent[x] != x:
            # 进行路径压缩
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    # 连通两个节点
    def union(self, p: int, q: int):
        rootP = self.find(p)
        rootQ = self.find(q)
        # 两个节点已经联通 根节点相同
        if rootP == rootQ:
            return
        # 将两颗树合并为一颗 联通p q
        #self.parent[rootP] = rootQ
        # 小树接到大的树下面
        if self.size[rootP] > self.size[rootQ]:
            self.parent[rootQ] = rootP
            self.size[rootP] += self.size[rootQ]
        else:
            self.parent[rootP] = rootQ
            self.size[rootQ] += self.size[rootP]

        # 连通分量减一
        self.count -= 1

    # 返回当前联通分量个数
    def count() -> int:
        return self.count

    # 判断两节点是否连通
    # 两联通节点的根节点一定相同
    def connected(self, p: int, q: int) -> bool:
        rootP = self.find(p)
        rootQ = self.find(q)
        return rootP == rootQ

class Solution:    
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        
        m, n = len(board), len(board[0])
        # dummy 假设那些不需要被替换的 O 都与 dummy连通
        # 给dummy留一个额外的位置
        uf = UF(m * n + 1)
        dummy = m * n
        # 将第一列和最后一列的 O 与dummy连通
        for i in range(m):
            if board[i][0] == 'O':
                uf.union(i * n, dummy)
            if board[i][-1] == 'O':
                uf.union(i * n + n - 1, dummy)
        # 将第一行和最后一行的 O 都与dummy连通
        for j in range(n):
            if board[0][j] == 'O':
                uf.union(j, dummy)
            if board[-1][j] == 'O':
                uf.union(n * (m - 1) + j, dummy)
        # 方向数组 d 是上下左右搜索的常用手法
        d = [[1, 0], [0, 1], [0, -1], [-1, 0]]
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                if board[i][j] == 'O':
                    # 将此位置的 O 与上下左右的 O 连通
                    for k in range(4):
                        x = i + d[k][0]
                        y = j + d[k][1]
                        if board[x][y] == 'O':
                            uf.union(x * n + y, i * n + j)
        # 所有不和dummy连通的 O 都要被替换
        for i in range(1, m - 1):
            for j in range(1, n - 1):
                if not uf.connected(dummy, i * n + j):
                    board[i][j] = 'X'
                    
"""
执行结果：通过 显示详情 添加备注
执行用时：272 ms, 在所有 Python3 提交中击败了7.64%的用户
内存消耗：19.9 MB, 在所有 Python3 提交中击败了12.47%的用户
"""


# 第990
# 判定合法等式
# 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
# 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

class Solution:
    
    class UF:
        def __init__(self, n: int):# n 为图的结点总数
            # 记录连通分量
            self.count = n
            # 记录节点 x 的父节点 parent[x]
            # 初始状态下每个节点的父节点是他自身
            self.parent = [i for i in range(n)]
            # 记录树的重量 初始状态下每棵树只有一个节点
            self.size = [1 for i in range(n)]

        def find(self, x: int) -> int:
            # 根节点的父节点是它自身
            while self.parent[x] != x:
                # 进行路径压缩
                self.parent[x] = self.parent[self.parent[x]]
                x = self.parent[x]
            return x

        # 连通两个节点
        def union(self, p: int, q: int):
            rootP = self.find(p)
            rootQ = self.find(q)
            # 两个节点已经联通 根节点相同
            if rootP == rootQ:
                return
            # 将两颗树合并为一颗 联通p q
            #self.parent[rootP] = rootQ
            # 小树接到大的树下面
            if self.size[rootP] > self.size[rootQ]:
                self.parent[rootQ] = rootP
                self.size[rootP] += self.size[rootQ]
            else:
                self.parent[rootP] = rootQ
                self.size[rootQ] += self.size[rootP]

            # 连通分量减一
            self.count -= 1

        # 返回当前联通分量个数
        def count() -> int:
            return self.count

        # 判断两节点是否连通
        # 两联通节点的根节点一定相同
        def connected(self, p: int, q: int) -> bool:
            rootP = self.find(p)
            rootQ = self.find(q)
            return rootP == rootQ
    
    def __init__(self):
        # 26个英文字母
        self.uf = self.UF(26)
    
    def equationsPossible(self, equations: List[str]) -> bool:
        # 先让相等的字母形成连通分量
        for eq in equations:
            if eq[1] == '=':
                x = eq[0]
                y = eq[-1]
                self.uf.union(ord(x) - ord('a'), ord(y) - ord('a'))
        # 检查不等关系是否破坏相等关系的连通性
        for eq in equations:
            if eq[1] == '!':
                x = eq[0]
                y = eq[-1]
                # 如果相等关系成立就是逻辑冲突
                if self.uf.connected(ord(x) - ord('a'), ord(y) - ord('a')):
                    return False
        return True
"""
执行结果：通过 显示详情 添加备注
执行用时：60 ms, 在所有 Python3 提交中击败了37.05%的用户
内存消耗：15.1 MB, 在所有 Python3 提交中击败了47.50%的用户
"""

