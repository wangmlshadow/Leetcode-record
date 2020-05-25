#include "normal.h"

/*
给你一个仅包含小写字母的字符串，请你去除字符串中重复的字母，使得每个字母
只出现一次。需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
*/

//  // https://leetcode-cn.com/problems/remove-duplicate-letters/solution/c-0ms-ji-bai-100jian-ming-dai-ma-chao-xiang-xi-jie/

class Solution {  // 栈
public:
    string removeDuplicateLetters(string s) {
        string res;

        for (int i = 0; i < s.length(); i++) {
            if (res.find(s[i]) != s.npos)  // 已存在代表所在位置此时是对的
                continue;

            while (!res.empty() && res.back() > s[i] && s.find(res.back(), i) != s.npos)
                res.pop_back();

            res.push_back(s[i]);
        }

        return res;
    }
};