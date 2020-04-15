#include "normal.h"

/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
*/

class Solution {   // 超时了
public:
    string shortestPalindrome(string s) {
        int len = s.length();

        if (len < 2)
            return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        for (int i = 0; i < len; i++) {
            if (s.substr(0, len - i) == rev.substr(i)) {
                rev += s.substr(len - i, i);
                break;
            }
        }

        return rev;
    }
};


class Solution {   // 递归
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        int i = 0;

        for (int j = len - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }

        if (i == len)
            return s;

        string rev = s.substr(i);
        reverse(rev.begin(), rev.end());

        return rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};