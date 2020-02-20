#include "normal.h"

/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";

        string str = strs[0];
        int i, j;

        for (i = 1; i < strs.size(); i++) {
            for (j = 0; j < min(str.length(), strs[i].length()); j++) {
                if (str[j] != strs[i][j])
                    break;
            }

            if (j == 0)
                return "";

            if (j < str.length())
                str = str.substr(0, j);
        }

        return str;
     }
};