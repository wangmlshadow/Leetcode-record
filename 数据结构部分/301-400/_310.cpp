#include "normal.h"

/*
对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最
小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 拓扑排序
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return { 0 };

        if (n == 2)
            return { 0, 1 };

        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int>(0));

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)
                q.push(i);

        int cntOne = q.size();

        while (n > 2) {
            n -= cntOne;

            while (cntOne-- != 0) {   // 一次性删除所有入度为1的节点
                int temp = q.front();
                q.pop();
                indegree[temp] = 0;

                for (int i = 0; i < graph[temp].size(); i++) {
                    if (indegree[graph[temp][i]] != 0) {
                        indegree[graph[temp][i]]--;

                        if (indegree[graph[temp][i]] == 1)
                            q.push(graph[temp][i]);
                    }
                }
            }

            cntOne = q.size();
        }

        vector<int> res;

        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};