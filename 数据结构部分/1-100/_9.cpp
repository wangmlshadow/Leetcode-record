#include "normal.h"

/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        stringstream ss;
        ss << x;
        string str = ss.str();
        int len = str.length();

        for (int i = 0; i <= len / 2; i++) {
            if (str[i] != str[len - i - 1])
                return false;
        }

        return true;
    }
};