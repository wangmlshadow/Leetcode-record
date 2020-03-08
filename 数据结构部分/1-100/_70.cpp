#include "normal.h"

/*

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/

class Solution {      // 递归超时了
public:
    int climbStairs(int n) {
        N = n;
        cnt = 0;

        solution(1);
        solution(2);

        return cnt;
    }

private:
    int N;
    int cnt;

    void solution(int nowCnt) {
        if (nowCnt == N) {
            cnt++;
            return;
        }
        else if (nowCnt > N) {
            return;
        }
        else {
            solution(nowCnt + 1);
            solution(nowCnt + 2);
        }
    }
};

class Solution {     // 动态规划
public:
    int climbStairs(int n) {
        vector<long> dp(n + 1, 0);

        if (n == 1)
            return 1;

        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};