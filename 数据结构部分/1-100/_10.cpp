#include "normal.h"

/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 有问题
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty())
            return true;

        if (!s.empty() && p.empty())
            return false;

        if (s.empty() && !p.empty()) {
            for (int i = 0; i < p.length(); i++) {
                if (p[i] == '.') {
                    if (i + 1 == p.length())
                        return true;
                    else {
                        if (p[i + 1] != '*') {
                            return isMatch(s, p.substr(i + 1));
                        }
                        else {
                            if (i + 2 == p.length())
                                return true;
                            else {
                                return isMatch(s, p.substr(i + 2));
                            }
                        }
                    }
                }
                else
                    return false;
            }
        }

        int i, j;

        for (i = 0, j = 0; i < p.length() && j < s.length(); ) {
            if (p[i] == '.') {
                if (i == p.length() - 1) {
                    return isMatch(s.substr(j), p.substr(i + 1)) || isMatch(s.substr(j + 1), p.substr(i + 1));
                }
                else {
                    if (p[i + 1] != '*')
                        return isMatch(s.substr(j), p.substr(i + 1)) || isMatch(s.substr(j + 1), p.substr(i + 1));
                    else {
                        int k;
                        for (k = j; k <= s.length(); k++) {
                            if (isMatch(s.substr(k), p.substr(i + 2)))
                                return true;
                        }
                        return false;
                    }
                }
            }
            else {
                if (p[i] == s[j]) {
                    if (i + 1 == p.length()) {
                        i++;
                        j++;
                    }
                    else {
                        if (p[i + 1] != '*') {
                            i++;
                            j++;
                        }
                        else {
                            if (isMatch(s.substr(j), p.substr(i + 2)) || isMatch(s.substr(j + 1), p.substr(i + 2)))
                                return true;

                            int k = j + 1;
                            while (k < s.length() && s[k] == p[i]) {
                                if (isMatch(s.substr(k + 1), p.substr(i + 2)))
                                    return true;
                            }

                            return false;
                        }
                    }
                }
                else {
                    if (i == p.length() - 1)
                        return false;
                    else {
                        if (p[i + 1] != '*')
                            return false;
                        else {
                            return isMatch(s.substr(j), p.substr(i + 2));
                        }
                    }
                }

            }
        }

        if (i == p.length() && j == s.length())
            return true;

        return false;
    }
};




class Solution {     // 参考https://leetcode-cn.com/problems/regular-expression-matching/solution/javahui-su-he-dong-tai-gui-hua-xiang-xi-dai-ma-zhu/
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        bool headMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (headMatch && isMatch(s.substr(1), p));
        }
        else if (headMatch)
            return isMatch(s.substr(1), p.substr(1));
        else
            return false;

    }
};

// 带备忘录的递归 或者说dp
class Solution {
public:
    bool isMatch(string s, string p) {
        _s = s;
        _p = p;
        _dp = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, 0));
        return dp(0, 0);
    }

private:
    string _s;
    string _p;
    vector<vector<int>> _dp;   // 0表示未计算 1表示true 2表示false
    bool dp(int i, int j) {
        if (_dp[i][j] != 0)
            return _dp[i][j] == 1;
        if (j == _p.length())
            return i == _s.length();
        bool first = i < _s.length() && (_p[j] == _s[i] || _p[j] == '.');
        bool ans;
        if (j <= _p.length() - 2 && _p[j + 1] == '*') {
            ans = dp(i, j + 2) || (first && dp(i + 1, j));
        }
        else {
            ans = first && dp(i + 1, j + 1);
        }

        _dp[i][j] = ans ? 1 : 2;
        return ans;
    }
};
/*
执行结果：通过 显示详情
执行用时：8 ms, 在所有 C++ 提交中击败了81.70%的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了45.22%的用户
*/
