#include "normal.h"

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。
*/

class Solution {   // 动态规划
public:
    int minCut(string s) {
        int len = s.length();

        if (len <= 1)
            return 0;

        vector<int> dp;

        for (int i = 0; i < len; i++)
            dp.push_back(i);

        // 建立一个用于判断回文子串的辅助数组，数组[begin][end]用于表示子串
        vector<vector<bool>> helper(len, vector<bool>(len, false));

        for (int end = 0; end < len; end++) {
            for (int begin = 0; begin <= end; begin++) {
                if (s[begin] == s[end] && (end - begin <= 2 || helper[begin + 1][end - 1]))
                    helper[begin][end] = true;
            }
        }

        for (int i = 1; i < len; i++) {
            if (helper[0][i]) {
                dp[i] = 0;
                continue;
            }

            for (int j = 0; j < i; j++) {
                if (helper[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[len - 1];
    }
};


class Solution {    // 试一下递归会不会超时   果然超时了
public:
    int minCut(string s) {
        len = s.length();
        minCnt = len;

        if (len == 0)
            return 0;

        vector<string> strs;

        solution(s, strs, 0, 1);

        return minCnt - 1;
    }

private:
    int len;
    //vector<vector<string>> res;
    int minCnt;

    bool isStr(string& s, int begin, int end) {   // 判断指定范围的子串是否为回文子串
        while (begin < end) {
            if (s[begin] != s[end])
                return false;

            begin++;
            end--;
        }

        return true;
    }

    void solution(string& s, vector<string> strs, int begin, int cnt) {
        if (begin >= len || begin + cnt > len)
            return;

        if (begin + cnt == len) {
            if (isStr(s, begin, begin + cnt - 1)) {
                int cur = strs.size() + 1;
                minCnt = min(cur, minCnt);               
            }
            return;
        }

        if (isStr(s, begin, begin + cnt - 1)) {
            vector<string> cur = strs;
            cur.push_back(s.substr(begin, cnt));
            solution(s, cur, begin + cnt, 1);
        }

        solution(s, strs, begin, cnt + 1);
    }
};