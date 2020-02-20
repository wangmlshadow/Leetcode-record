#include "normal.h"

/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
*/

// 回溯法

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        backtrack(result, "", 0, 0, n);

        return result;
    }

    void backtrack(vector<string>& str, string cur, int left, int right, int n) {
        if (cur.length() == 2 * n) {
            str.push_back(cur);
            return;
        }

        if (left < n)
            backtrack(str, cur + "(", left + 1, right, n);

        if (right < left)
            backtrack(str, cur + ")", left, right + 1, n);
    }
};