# Union-Find 动态连通性问题
# 主要是解决图论中动态连通性问题

class UF:
    def __init__(self, n: int):# n 为图的结点总数
        # 记录连通分量
        self.count = n
        # 记录节点 x 的父节点 parent[x]
        # 初始状态下每个节点的父节点是他自身
        self.parent = [i for i in range(n)]
    
    # 返回节点 x 的根节点
    def find(self, x: int) -> int:
        # 根节点的父节点是它自身
        while self.parent[x] != x:
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
        self.parent[rootP] = rootQ# 这里简单的将一颗树连接到另一棵树的根节点 可能造成不平衡状态
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
# 上述算法花费时间基本都在find上 find最极端情况下复杂度为 O(N)

# 为了解决上述的树的不平衡问题 
# 我们希望小一些的树接到大一些的树下面 这样可以避免头重脚轻 使得树更加平衡
# 解决方法是记录每棵树的大小
class UF:
    def __init__(self, n: int):# n 为图的结点总数
        # 记录连通分量
        self.count = n
        # 记录节点 x 的父节点 parent[x]
        # 初始状态下每个节点的父节点是他自身
        self.parent = [i for i in range(n)]
        # 记录树的重量 初始状态下每棵树只有一个节点
        self.size = [1 for i in range(n)]
    
    # 返回节点 x 的根节点
    def find(self, x: int) -> int:
        # 根节点的父节点是它自身
        while self.parent[x] != x:
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
      
# 路径压缩
# 进一步压缩每棵树的高度 使得树的高度保持为常数

# 使得树的高度不超过3 只需要修改find
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
# find时间复杂度变为 O(1)
# 于此同时其他操作复杂度也下降为 O(1)
