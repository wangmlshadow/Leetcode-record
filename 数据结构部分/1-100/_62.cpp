#include "normal.h"

/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 超时
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        int cnt = 0;
        getCnt(1, 1, cnt);

        return cnt;
    }

private:
    int M;    // 列
    int N;    // 行

    void getCnt(int m, int n, int& cnt) {
        if (m == M && n == N) {
            cnt++;
            return;
        }
        else if (m > M || n > N)
            return;
        else {
            getCnt(m + 1, n, cnt);
            getCnt(m, n + 1, cnt);
        }
    }
};

class Solution {   // 动态规划
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 1));

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[n - 1][m - 1];
    }
};