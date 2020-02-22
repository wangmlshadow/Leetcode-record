#include "normal.h"

/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> mySt;
        int len = 0;
        mySt.push(-1);  // 注意此处

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                mySt.push(i);
            else {
                mySt.pop();

                if (mySt.empty())
                    mySt.push(i);     // 保证不存在空栈， 栈中要么时-1，要么是第一个有效位置
                else {
                    len = (len > i - mySt.top()) ? len : i - mySt.top();
                }
            }
        }

        return len;
    }
};