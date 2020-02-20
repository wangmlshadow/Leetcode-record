#include "normal.h"


/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;

        for (int i = 0; i != s.length(); i++) {
            int l1 = GetMaxSubStrForThePos(s, i, i);
            int l2 = GetMaxSubStrForThePos(s, i, i+1);
            int l = (l1 > l2) ? l1 : l2;
            if (l > right - left + 1) {
                left = i - (l - 1) / 2;
                right = i + l / 2;
            }
        }
        return s.substr(left, right - left + 1);
    }

    int GetMaxSubStrForThePos(string s, int star, int end) {
        while (star >= 0 && end < s.length() && s[star] == s[end]) {
            star--;
            end++;
        }
        return end - star - 1;
    }
};


// 还有更优解，以后再看