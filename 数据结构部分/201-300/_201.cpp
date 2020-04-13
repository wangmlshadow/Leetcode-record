#include "normal.h"

/*
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。
*/

class Solution {   // 肯定超时了
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;

        for (int i = m + 1; i <= n; i++)
            res &= i;

        return res;
    }
};

class Solution { // 通过所有测试用例 但是报出超时
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;

        int sub = n - m;

        if (sub >= m)
            return 0;

        int res = m;

        for (int i = m + 1; i <= n; i++) {
            res &= i;

            if (res == 0 || i == INT_MAX)
                break;
        }
        return res;
    }
};

class Solution {  // 运行速度>73%
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n)
            return m;

        int cnt = 0; // 最后结果右边0的个数

        while (n > m) {
            cnt++;
            n >>= 1;
            m >>= 1;
        }

        return m << cnt;
    }
};

class Solution {  // 运行速度>13%
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m) {
            n &= (n - 1);
        }

        return n;
    }
};

class Solution {  // 运行速度>49%
public:
    int rangeBitwiseAnd(int m, int n) {
        if (n - m >= m)
            return 0;

        while (n > m) {
            n &= (n - 1);
        }

        return n;
    }
};