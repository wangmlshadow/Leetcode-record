/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个
字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串
的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但
与"aa.a"和"ab*a"均不匹配。
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        res = false;
        match(s, p, 0, 0);
        return res;
    }

    void match(string& s, string& p, int sPos, int pPos) {
        if (res) {
            return;
        }
        if (sPos >= s.length() && pPos >= p.length()) {// 字符串和模式串都匹配完成 表示匹配成功
            res = true;
            return;
        }
        // 带 * 的情况
        if (pPos + 1 < p.length() && p[pPos + 1] == '*') {
            if (sPos < s.length() && (s[sPos] == p[pPos] || p[pPos] == '.')) {
                match(s, p, sPos + 1, pPos);
            }
            match(s, p, sPos, pPos + 2);
        }
        // 不带 * 的情况
        if ((sPos < s.length() && pPos < p.length()) && (s[sPos] == p[pPos] || p[pPos] == '.') && (pPos + 1 >= p.length() || p[pPos + 1] != '*')) {
            match(s, p, sPos + 1, pPos + 1);
        }
    }
private:
    bool res;
};
/*
执行结果：通过 显示详情 添加备注
执行用时：44 ms, 在所有 C++ 提交中击败了19.25%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了86.33%的用户
*/