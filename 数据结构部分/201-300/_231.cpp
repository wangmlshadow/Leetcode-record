#include "normal.h"

/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n > 2) {
            if (n % 2 != 0)
                return false;

            n >>= 1;
        }

        return true;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n > 2) {
            if (n & 1 != 0)
                return false;

            n >>= 1;
        }

        return true;
    }
};