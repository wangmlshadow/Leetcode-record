"""
785 判断二分图
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个
来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个
在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并
且graph[i]中没有重复的值。

邻接表 graph[i][]  表示与i相连的顶点
"""
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        visited = [0] * len(graph)
        ans = True
        # 使用0表示未访问
        # 使用1  2表示二分图两种节点
        # DFS
        def traverse(p: int, i: int):
            nonlocal visited, ans
            if visited[i] != 0:
                if visited[i] == visited[p]:
                    ans = False
                    return None
            else:
                if p == -1:
                    visited[i] = 1
                else:
                    visited[i] = 2 if visited[p] == 1 else 1
                for j in range(len(graph[i])):
                    traverse(i, graph[i][j])                                
        
        for i in range(len(graph)):
            if visited[i] == 0:
                traverse(-1, i)
        
        return ans
                

"""
执行结果：通过 显示详情
执行用时：224 ms, 在所有 Python3 提交中击败了60.51%的用户
内存消耗：14.2 MB, 在所有 Python3 提交中击败了5.92%的用户
"""
