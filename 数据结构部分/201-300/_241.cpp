#include "normal.h"

/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出
不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.length();

        if (len == 0)
            return vector<int>();

        if (mem.find(input) != mem.end())
            return mem[input];

        vector<int> res;
        int num = 0;
        int index = 0;

        while (index < len && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';

        if (index == len) {
            res.push_back(num);
            mem[input] = res;
            return res;
        }

        for (int i = 0; i < len; i++) {
            if (!isdigit(input[i])) {  // 遇到操作符 将input分为左右两部分
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));

                for (auto left : res1) {
                    for (auto right : res2) {
                        char op = input[i];
                        res.push_back(caculate(left, op, right));
                    }
                }
            }
        }

        mem[input] = res;
        return res;
    }

private:
    map<string, vector<int>> mem;

    int caculate(int left, char op, int right) {
        switch (op) {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        }

        return -1;
    }
};