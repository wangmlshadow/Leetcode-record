#include "normal.h"

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        int start = 0;
        int end = 0;
        int len = 1;
        int i, j;

        for (i = 1; i < s.length(); i++) {
            for (j = start; j <= end; j++) {
                if (s[i] == s[j]) {
                    break;
                }
            }

            if (j > end) {
                end = i;
            }
            else {
                len = (len < i - start) ? (i - start) : len;
                start = j + 1;
                end = i;
            }           
        }

        return (len < i - start) ? (i - start) : len;
    }
};