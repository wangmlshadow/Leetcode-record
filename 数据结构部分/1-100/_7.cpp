#include "normal.h"

/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

INT_MAX,INT_MIN由标准头文件<limits.h>定义。
INT_MAX=2^31-1(2,147,483,647)
INT_MIN=-2^31(-2,147,483,648)
*/

class Solution {
public:
    int reverse(int x) {
        bool temp;
        long val = x;

        if (val < 0) {
            temp = false;
            val = 0 - val;
        }
        else {
            temp = true;
            val = x;
        }

        stringstream ss;
        ss << val;

        string s = ss.str();

        for (int i = 0; i < s.length() / 2; i++) {
            char c = s[i];
            s[i] = s[s.length() - i - 1];
            s[s.length() - i - 1] = c;
        }

        long tempval;
        stringstream  sss;
        sss << s;
        sss >> tempval;

        if (temp) {
            if (tempval > INT_MAX)
                return 0;
            else
                return (int)tempval;
        }
        else {
            if ((0 - tempval < INT_MIN))
                return 0;
            else
                return (int)(0 - tempval);
        }

    }
};