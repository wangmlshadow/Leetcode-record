#include "normal.h"

/*
给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
*/

class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);

        while (s.length() != 1) {
            int cur = 0;

            for (auto c : s) {
                cur = cur + c - '0';
            }

            s = to_string(cur);
        }

        return stoi(s);
    }
};

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};