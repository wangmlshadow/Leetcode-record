#include "normal.h"

/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
*/

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;

        for (long long i = 1; i <= n; i *= 10) {
            long long div = i * 10;
            cnt += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
        }

        return cnt;
    }
};