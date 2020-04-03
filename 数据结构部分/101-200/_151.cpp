#include "normal.h"

/*
给定一个字符串，逐个翻转字符串中的每个单词。
*/

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        int i = 0;

        while (i < len && s[i] == ' ')
            i++;

        if (i == len)
            return "";

        vector<string> helper;
        string res;       

        for ( ; i < len; i++) {
            while (i < len && s[i] == ' ')
                i++;

            if (i >= len)
                break;

            string temp;

            while (i < len && s[i] != ' ')
                temp.push_back(s[i++]);

            helper.push_back(temp);
        }

        int size = helper.size();
        res = helper[size - 1];

        for (i = size - 2; i >= 0; i--) {
            res = res + " " + helper[i];
        }        

        return res;
    }
};