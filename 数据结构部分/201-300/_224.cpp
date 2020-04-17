#include "normal.h"

/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
*/

class Solution {
public:
    int calculate(string s) {
        vector<string> RPN;
        stack<string> op;
        int len = s.length();

        for (int i = 0; i < len; i++) {  // 转化为逆波兰式
            if (s[i] == ' ')
                continue;
            else if (s[i] == '(')
                op.push("(");
            else if (s[i] == ')') {
                while (!op.empty()) {
                    if (op.top() != "(") {
                        RPN.push_back(op.top());
                        op.pop();
                    }
                    else {
                        op.pop();
                        break;
                    }
                }
            }
            else if (s[i] == '+') {
                if (op.empty())
                    op.push("+");
                else {
                    while (!op.empty() && op.top() != "(") {
                        RPN.push_back(op.top());
                        op.pop();
                    }

                    op.push("+");
                }
            }
            else if (s[i] == '-') {
                if (op.empty())
                    op.push("-");
                else {
                    while (!op.empty() && op.top() != "(") {
                        RPN.push_back(op.top());
                        op.pop();
                    }

                    op.push("-");
                }
            }
            else {
                string num;
                num.push_back(s[i]);

                while (i + 1 < len && isdigit(s[i + 1])) {
                    num.push_back(s[i + 1]);
                    i++;
                }

                RPN.push_back(num);
            }
        }

        while (!op.empty()) {
            RPN.push_back(op.top());
            op.pop();
        }

        stack<int> res;

        for (auto str : RPN) {  // 逆波兰式求值
            if (str == "+") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y + x);
            }
            else if (str == "-") {
                int x = res.top();
                res.pop();
                int y = res.top();
                res.pop();
                res.push(y - x);
            }
            else {
                res.push(stoi(str));
            }
        }

        return res.top();
    }
};