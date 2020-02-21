#include "normal.h"

/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 最直接的方法，但是比较慢
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;

        long temp_1 = dividend;
        long temp_2 = divisor;

        if (divisor == 1)
            return dividend;

        if (divisor == -1) {
            temp_1 = 0 - temp_1;

            if (temp_1 > INT_MAX)
                return INT_MAX;
            else if (temp_1 < INT_MIN)
                return INT_MIN;
            else
                return temp_1;
        }

        bool plus_minus;

        if ((temp_1 > 0 && temp_2 > 0) || (temp_1 < 0 && temp_2 < 0))
            plus_minus = true;
        else
            plus_minus = false;

        temp_1 = abs(temp_1);
        temp_2 = abs(temp_2);

        long cnt = 0;
        long temp = temp_1 - temp_2;

        while (temp >= 0) {
            cnt++;
            temp -= temp_2;
        }

        if (!plus_minus)
            cnt = 0 - cnt;

        if (cnt > INT_MAX)
            return INT_MAX;
        else if (cnt < INT_MIN)
            return INT_MIN;
        else
            return cnt;
    }
};


class Solution {   // 思路来自解答https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;

        long temp_1 = dividend;
        long temp_2 = divisor;

        if (divisor == 1)
            return dividend;

        if (divisor == -1) {
            temp_1 = 0 - temp_1;

            if (temp_1 > INT_MAX)
                return INT_MAX;
            else if (temp_1 < INT_MIN)
                return INT_MIN;
            else
                return temp_1;
        }

        bool plus_minus;

        if ((temp_1 > 0 && temp_2 > 0) || (temp_1 < 0 && temp_2 < 0))
            plus_minus = true;
        else
            plus_minus = false;

        temp_1 = abs(temp_1);
        temp_2 = abs(temp_2);
        long cnt = divide_2(temp_1, temp_2);
        
        if (!plus_minus)
            cnt = 0 - cnt;

        if (cnt > INT_MAX)
            return INT_MAX;
        else if (cnt < INT_MIN)
            return INT_MIN;
        else
            return cnt;
    }

    int divide_2(long a, long b) {
        if (a < b)
            return 0;

        long cnt = 1;
        long temp = b;

        while (temp + temp <= a) {
            cnt = cnt + cnt;
            temp = temp + temp;
        }

        return cnt + divide_2(a - temp, b);
    }
};