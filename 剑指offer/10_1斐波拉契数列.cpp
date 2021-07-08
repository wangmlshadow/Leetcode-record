/*
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        long long n0 = 0, n1 = 1, temp;// 测试用例 long long 都会溢出 需要每一步都取模
        long long mod = 1000000007;
        while (n > 1) {
            temp = n0;
            n0 = n1 % mod;
            n1 = (temp + n1) % mod;
            --n;
        }
        return (int)(n1 % mod);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了39.30%的用户
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        // 换成int内存消耗会小一点点
        int n0 = 0, n1 = 1, temp;
        int mod = 1000000007;
        while (n > 1) {
            temp = n0;
            n0 = n1 % mod;
            n1 = (temp + n1) % mod;
            --n;
        }
        return n1;
    }
};