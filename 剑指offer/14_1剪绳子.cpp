/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整
数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问
k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度
是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积
是18。
*/

// 动态规划
class Solution {
public:
    int cuttingRope(int n) {
        // 绳子长度为n 切成m段
        // res[n][m]表示长为n的绳子 切成m段 的最大乘积
        // m > 2 最少切两段你最多切n次
        vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            res[i][1] = i; // 长为 i 的绳子切成 1 段 虽然题目要求最少切成两段 但是这个在后面需要使用
            res[i][i] = 1; // 长为 i 的绳子切成 i 段
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                int max = 0;
                for (int k = 1; k < i; ++k) {
                    if (max < k * res[i - k][j - 1]) {
                        max = k * res[i - k][j - 1];
                    }
                }
                res[i][j] = max;
            }
        }

        int result = 0;
        for (int i = 2; i <= n; ++i) {
            if (result < res[n][i]) {
                result = res[n][i];
            }
        }

        return result;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了23.45%的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了5.27%的用户
*/

// 优化一下
class Solution {
public:
    int cuttingRope(int n) {
        // 绳子长度为n 切成m段
        // res[n][m]表示长为n的绳子 切成m段 的最大乘积
        // m > 2 最少切两段你最多切n次
        vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));
        // 长为 i 的绳子切成 i 段
        for (int i = 1; i <= n; ++i) {
            res[i][1] = i;
            res[i][i] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                int max = 0;
                for (int k = 2; k < i; ++k) {
                    if (res[i - k][j - 1] == 0) {
                        break;
                    }
                    if (max < k * res[i - k][j - 1]) {
                        max = k * res[i - k][j - 1];
                    }
                }
                res[i][j] = max;
            }
        }

        int result = 0;
        for (int i = 2; i <= n; ++i) {
            if (result < res[n][i]) {
                result = res[n][i];
            }
        }

        return result;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了23.45%的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了5.27%的用户
*/