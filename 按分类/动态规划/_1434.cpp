#include "normal.h"

/*
动态规划

总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40 。

给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表。

请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数。

由于答案可能很大，请返回它对 10^9 + 7 取余后的结果。

n == hats.length
1 <= n <= 10
1 <= hats[i].length <= 40
1 <= hats[i][j] <= 40
hats[i] 包含一个数字互不相同的整数列表。


*/

class Solution {  // 回溯   超时
public:
    int numberWays(vector<vector<int>>& hats) {
        hats_ = hats;
        used_ = vector<bool>(41, false);
        return dfs(0);
    }

private:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> hats_;
    vector<bool> used_;    // 标记四十种帽子每种帽子是否被使用

    int dfs(int i) {   // 从第0个到第n-1个人选帽子，0-i的人帽子已经选好，返回i+1到n-1的人选帽子的方案数
        if (i == hats_.size())
            return 1;  // 所有人帽子都选好了

        int res = 0;

        for (auto hat : hats_[i]) {
            if (!used_[hat]) {   // 回溯
                used_[hat] = true;
                res = (res + dfs(i + 1)) % MOD;
                used_[hat] = false;
            }
        }

        return res;
    }
};

class Solution {  // 超时？  这应该不算dp，就是一个备忘录
public:
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        hats_ = hats;
        return dfs(0, (long long)0);
    }

private:
    static const int MOD = 1e9 + 7;
    map<long long, int> dp;   // long long的二进制数的每一位表示帽子的使用情况，1表示使用，0表示未使用，dp记录每个情况的方案数
    vector<vector<int>> hats_;
    int n;

    int dfs(int i, long long used) {
        if (i == n)
            return 1;

        if (dp.count(used) != 0)
            return dp[used];

        int res = 0;

        for (auto hat : hats_[i]) {
            if ((used & (1 << hat)) == 0) {
                res = (res + dfs(i + 1, used | (1 << hat))) % MOD;
            }
        }

        dp[used] = res;
        return res;
    }
};

class Solution {  // 通过每个人能带哪些帽子求解超时，下面试试转化为每个帽子可以用在哪些人身上
public:
    int numberWays(vector<vector<int>>& hats) {
        people = vector<vector<int>>(41);

        for (int i = 0; i < hats.size(); i++) {
            for (auto h : hats[i])   // 1 <= h <= 40
                people[h].push_back(i);
        }
        complete = (1 << hats.size()) - 1;

        return dfs(0, 0);
    }

private:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> people;   // 每个帽子适合哪些人
    unordered_map<int, vector<int>> dp;             // key表示n个人是否戴上了帽子
    int complete;    // 所有人都有帽子的状态


    int dfs(int i, int person) {
        if (person == complete)
            return 1;

        if (i >= 41) {  // 帽子分完了
            return 0;
        }

        if (dp.count(person) != 0 && dp[person][i] != -1) {
            return dp[person][i];
        }

        int res = dfs(i + 1, person);

        for (auto p : people[i]) {
            if ((person & (1 << p)) == 0) {
                res = (res + dfs(i + 1, person | (1 << p))) % MOD;
            }
        }

        if (dp.count(person) == 0)
            dp[person] = vector<int>(41, -1);

        dp[person][i] = res;
        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：280 ms, 在所有 C++ 提交中击败了9.94%的用户
内存消耗：18.5 MB, 在所有 C++ 提交中击败了7.32%的用户
*/

// 上一种情况对应的dfs
class Solution {  
public:
    int numberWays(vector<vector<int>>& hats) {
        n = hats.size();
        have = vector<bool>(n, false);
        people = vector<vector<int>>(41);

        for (int i = 0; i < hats.size(); i++) {
            for (auto h : hats[i])   // 1 <= h <= 40
                people[h].push_back(i);
        }

        return dfs(0, 0);
    }

private:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> people; 
    int n;
    vector<bool> have;

    int dfs(int i, int cnt) {
        if (cnt == n)
            return 1;

        if (i >= 42)
            return 0;

        int res = dfs(i + 1, cnt);

        for (auto p : people[i]) {
            if (!have[p]) {
                have[p] = true;
                res = (res + dfs(i + 1, cnt + 1)) % MOD;
                have[p] = false;
            }
        }

        return res;
    }
};
