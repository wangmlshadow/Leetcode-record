#include "normal.h"

/*

你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
*/

class Solution {  // 判断图中是否有环 拓扑排序
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int size = prerequisites.size();

        for (int i = 0; i < size; i++) {
            indegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        int cnt = 0;

        while (!q.empty()) {
            int point = q.front();
            q.pop();
            cnt++;
            int numOut = graph[point].size();

            for (int i = 0; i < numOut; i++) {
                indegree[graph[point][i]]--;

                if (indegree[graph[point][i]] == 0)
                    q.push(graph[point][i]);
            }
        }

        return cnt == numCourses;
    }
};