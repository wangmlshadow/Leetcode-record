#include "normal.h"

/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/wildcard-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 超时
public:
    bool isMatch(string s, string p) {
        bool one = false;

        isMatch_x(s, p, one);

        return one;
    }

    bool isMatch_x(string s, string p, bool& one) {
        if (one)
            return true;

        if (s.empty()) {
            if (p.empty()) {
                one = true;
                return true;
            }
            else {
                int i = 0;
                while (p[i] == '*' && i < p.length())
                    i++;

                if (i == p.length()) {
                    one = true;
                    return true;
                }
                else
                    return false;
            }
        }

        if (!s.empty() && p.empty())
            return false;
        
        if (p[0] == '?') {
            isMatch_x(s.substr(1), p.substr(1), one);
        }
        else if (p[0] == '*') {   // 一个星号和n个星号表示同样的意思
            int cnt = 0;
            while (p[cnt] == '*' && cnt < p.length())
                cnt++;

            for (int i = 0; i <= s.length(); i++) {
                isMatch_x(s.substr(i), p.substr(cnt), one);
            }               
        }
        else {
            if (s[0] == p[0])
                isMatch_x(s.substr(1), p.substr(1), one);
        }

        return false;
    }
};



class Solution {     // 还是超时
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        if (s.empty()) {
            int i = 0;
            while (p[i] == '*' && i < p.length())
                i++;

            if (i == p.length()) {
                return true;
            }
            else
                return false;
        }
        else {
            if (s[0] == p[0] || p[0] == '?')
                return isMatch(s.substr(1), p.substr(1));
            else if (p[0] == '*') {
                int cnt = 0;
                while (p[cnt] == '*' && cnt < p.length())
                    cnt++;

                return isMatch(s, p.substr(cnt)) || isMatch(s.substr(1), p.substr(cnt - 1));
            }
            else
                return false;
        }
    }
};     // 除了清理星号，还要记录下已测试过的步骤，防止重复


// 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();

        vector<vector<bool>> dp(len_s + 1, vector<bool>(len_p + 1, false));
        // 初始化
        dp[0][0] = true;
        for (int i = 1; i <= len_p; i++) {    // 用s的空匹配p，填dp第0行
            dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
        }

        for (int i = 1; i <= len_s; i++) {    // 依次填dp，从第一行往后
            for (int j = 1; j <= len_p; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];    // 星号做空字符或代替掉s的n个字符
                else
                    ;
            }
        }
        
        return dp[len_s][len_p];   // 最后结果
    }
};

