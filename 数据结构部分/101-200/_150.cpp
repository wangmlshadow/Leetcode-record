#include "normal.h"

/*
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> helper;
        int size = tokens.size();
        int i = 0;

        while (i < size) {
            string cur = tokens[i++];

            if (cur == "+") {
                int second = helper.top();
                helper.pop();
                int first = helper.top();
                helper.pop();
                helper.push(first + second);
            }
            else if (cur == "-") {
                int second = helper.top();
                helper.pop();
                int first = helper.top();
                helper.pop();
                helper.push(first - second);
            }
            else if (cur == "*") {
                int second = helper.top();
                helper.pop();
                int first = helper.top();
                helper.pop();
                helper.push(first * second);
            }
            else if (cur == "/") {
                int second = helper.top();
                helper.pop();
                int first = helper.top();
                helper.pop();
                helper.push(first / second);
            }
            else {   // 有效数字
                int val = atoi(cur.c_str());
                helper.push(val);
            }
        }

        return helper.top();
    }
};