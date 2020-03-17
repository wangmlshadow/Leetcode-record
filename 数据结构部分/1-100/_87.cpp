#include "normal.h"

/*
给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len_1 = s1.length();
        int len_2 = s2.length();

        if (len_1 != len_2)
            return false;

        vector<vector<vector<bool>>> dp(len_1, vector<vector<bool>>(len_1, vector<bool>(len_1 + 1, false)));

        for (int i = 0; i < len_1; i++) 
            for (int j = 0; j < len_1; j++) 
                dp[i][j][1] = s1[i] == s2[j];
            
        for (int len = 2; len <= len_1; len++) {
            for (int i = 0; i <= len_1 - len; i++) {
                for (int j = 0; j <= len_1 - len; j++) {
                    for (int k = 1; k < len; k++) {
                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }

                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            dp[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0][0][len_1];
    }
};