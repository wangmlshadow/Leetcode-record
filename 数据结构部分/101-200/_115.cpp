#include "normal.h"

/*
给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distinct-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int len_1 = s.length();
        int len_2 = t.length();

        if (len_1 == 0 || len_1 < len_2)
            return 0;

        vector<vector<long>> dp(len_2 + 1, vector<long>(len_1 + 1, 0));

        for (int i = 0; i <= len_1; i++)
            dp[0][i] = 1;

        for (int i = 1; i <= len_2; i++) {
            for (int j = 1; j <= len_1; j++) {
                if (s[j - 1] == t[i - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        
        return dp[len_2][len_1];
    }
};
