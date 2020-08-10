#include "normal.h"

/*
动态规划

给定一个正整数 x，我们将会写出一个形如 x (op1) x (op2) x (op3) x ... 的表达式，其中每个运
算符 op1，op2，… 可以是加、减、乘、除（+，-，*，或是 /）之一。例如，对于 x = 3，我们可以
写出表达式 3 * 3 / 3 + 3 - 3，该式的值为 3 。

在写这样的表达式时，我们需要遵守下面的惯例：

除运算符（/）返回有理数。
任何地方都没有括号。
我们使用通常的操作顺序：乘法和除法发生在加法和减法之前。
不允许使用一元否定运算符（-）。例如，“x - x” 是一个有效的表达式，因为它只使用减法，但
是 “-x + x” 不是，因为它使用了否定运算符。 
我们希望编写一个能使表达式等于给定的目标值 target 且运算符最少的表达式。返回所用运算符
的最少数量。

思路：要找到最少数量，那么显示x不断相乘接近target，再求剩下部分数字如何表示

已知：
x^n < target <x^(n+1)

令x^n+a=target,x^(n+1)-b=target

令left = f(target),right = f(b)

则可知 target + b = x^(n+1)

当 target<b的情况下，left<=right.
*/

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        return dp(x, target);
    }

private:
    map<int, int> memo;

    int dp(int x, int target) {
        if (memo.find(target) != memo.end())
            return memo[target];

        if (target < x)
           return memo[target] = min(2 * target - 1, (x - target) * 2);   // 最小单元

        if (target == 0)
            return memo[0] = 0;

        double tmp = log((double)target) / log((double)x);
        long long p = (long long)tmp;
        long long sum = pow(x, p);
        long long ans = dp(x, target - sum) + p;

        // target > b 时 可能left > right
        if (sum * x - target < target)
            ans = min(ans, p + 1 + dp(x, sum * x - target));

        return memo[target] = ans;
    }
};

/*
执行结果：通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了94.23%的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了20.00%的用户
*/