#include "normal.h"

/*
动态规划

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。
*/

class Solution {  // 不通过
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        if (desiredTotal == 0 || maxChoosableInteger >= desiredTotal)
            return true;

        vector<int> dp(1 << maxChoosableInteger, 0);  // 0表示未初始化，1表示true，2表示false
        return dfs(maxChoosableInteger, desiredTotal, 0, dp);
    }

private:
    bool dfs(int maxChoosableInteger, int desireTotal, int state, vector<int>& dp) {
        if (dp[state] != 0)
            return dp[state] == 1;

        for (int i = maxChoosableInteger; i > 0; i--) {
            int tmp = 1 << (i - 1);   // 1 << (i - 1)

            if (state & tmp != 0) {   // 此处有问题  
                                      // 修改为(state & tmp) != 0  就通过了
                                      // != 优先级高于 & 操作
                continue;
            }

            if (i >= desireTotal || !dfs(maxChoosableInteger, desireTotal - i, state | tmp, dp)) {
                dp[state] = 1;
                return true;
            }
        }

        dp[state] = 2;
        return false;
    }
};

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;

        if (desiredTotal == 0 || maxChoosableInteger >= desiredTotal)
            return true;

        vector<int> dp(1 << maxChoosableInteger, 0);
        return dfs(maxChoosableInteger, 0, desiredTotal, dp);
    }

    bool dfs(int n, int stat, int target, vector<int>& dp) {
        if (dp[stat] != 0)
            return dp[stat] == 1;

        for (int i = n; i > 0; i--) {
            int cur = 1 << (i - 1);

            if ((stat & cur) != 0)
                continue;

            if (i >= target || !dfs(n, stat | cur, target - i, dp)) {
                dp[stat] = 1;
                return true;
            }
        }

        dp[stat] = 2;
        return false;
    }
};

/*
执行结果：通过 显示详情
执行用时：28 ms, 在所有 C++ 提交中击败了82.97%的用户
内存消耗：36 MB, 在所有 C++ 提交中击败了46.34%的用户
*/