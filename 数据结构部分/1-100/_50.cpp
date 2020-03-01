#include "normal.h"

/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/

class Solution {   // 超时
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;

        double result = 1;
        int cnt = abs(n);

        for (int i = 0; i < cnt; i++) {
            result *= x;
        }

        if (n > 0)
            return result;
        else
            return 1 / result;
    }
};


class Solution {    // 超时
public:
    double myPow(double x, int n) {
        long cnt = n;

        if (cnt < 0) {
            x = 1 / x;
            cnt = -cnt;
        }

        double result = 1.0;

        for (long i = 0; i < cnt; i++)
            result = x * result;

        return result;
    }
};



// 快速幂算法

class Solution {
public:
    double myPow(double x, int n) {
        long cnt = n;

        if (cnt < 0) {
            x = 1 / x;
            cnt = -cnt;
        }

        return myPow_2(x, cnt);
    }

    double myPow_2(double x, int n) {
        if (n == 0)
            return 1.0;

        double half = myPow_2(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        }
        else {
            return half * half * x;
        }
    }
};