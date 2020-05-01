#include "normal.h"

/*
删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。

说明: 输入可能包含了除 ( 和 ) 以外的字符。
*/

class Solution {   // 有限的回溯
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        int len = s.length();

        for (int i = 0; i < len; i++) {
            if (s[i] == '(')
                left++;
            else if (s[i] == ')') {
                right = left == 0 ? right + 1 : right;
                left = left > 0 ? left - 1 : left;
            }
        }

        recurse(s, 0, 0, 0, left, right, "");

        vector<string> curRes;

        for (auto str : res)
            curRes.push_back(str);
       
        return curRes;
    }

private:
    set<string> res;   // 防止出现重复结果 

    void recurse(string& s, int index, int leftCount, int rightCount, int leftRem, int rightRem, string cur) {
        if (index == s.length()) {
            if (leftRem == 0 && rightRem == 0)
                res.insert(cur);
        }
        else {
            if ((s[index] == '(' && leftRem > 0) || (s[index] == ')' && rightRem > 0)) {
                recurse(s, index + 1, leftCount, rightCount, leftRem - (s[index] == '(' ? 1 : 0), rightRem - (s[index] == ')' ? 1 : 0), cur);
            }

            cur.push_back(s[index]);

            if (s[index] != '(' && s[index] != ')')
                recurse(s, index + 1, leftCount, rightCount, leftRem, rightRem, cur);
            else if (s[index] == '(')
                recurse(s, index + 1, leftCount + 1, rightCount, leftRem, rightRem, cur);
            else {
                if (rightCount < leftCount)
                    recurse(s, index + 1, leftCount, rightCount + 1, leftRem, rightRem, cur);
            }

            cur.pop_back();
        }
    }
};