#include "normal.h"

/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;

        stack<char> mySt;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                mySt.push(s[i]);
            else {
                if (mySt.empty())
                    return false;

                bool temp = false;

                if (s[i] == ')' && mySt.top() == '(')
                    temp = true;

                if (s[i] == '}' && mySt.top() == '{')
                    temp = true;

                if (s[i] == ']' && mySt.top() == '[')
                    temp = true;

                if (temp)
                    mySt.pop();
                else
                    return false;
            }
        }

        return mySt.empty();
    }
};