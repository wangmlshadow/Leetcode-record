#include "normal.h"

/*

现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int size = prerequisites.size();
        vector<int> res;

        for (int i = 0; i < size; i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int point = q.front();
            q.pop();
            res.push_back(point);
            int numOut = graph[point].size();

            for (int i = 0; i < numOut; i++) {
                indegree[graph[point][i]]--;

                if (indegree[graph[point][i]] == 0)
                    q.push(graph[point][i]);
            }
        }

        if (res.size() == numCourses)
            return res;
        
        return {};
    }
};