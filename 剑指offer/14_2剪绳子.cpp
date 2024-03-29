/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段
绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是
多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积
是18。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4) {
            return n - 1;
        }
        int mod = 1000000007;
        // 动态规划不行 会溢出
        // 尽可能把绳子分成长度为3的小段，这样乘积最大 证明网站题解
        long long res = 1;
        while (n > 4) {
            res = 3 * res % mod;
            n -= 3;
        }
        return res * n % mod;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了58.86%的用户
*/