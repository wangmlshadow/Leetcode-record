#include "normal.h"

/*
动态规划

行程长度编码 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和
表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 "aabccc" ，将 "aa" 替换为 "a2" ，"ccc" 替
换为` "c3" 。因此压缩后的字符串变为 "a2bc3" 。

注意，本问题中，压缩时没有在单个字符后附加计数 '1' 。

给你一个字符串 s 和一个整数 k 。你需要从字符串 s 中删除最多 k 个字符，以使 s 的行程长度编码长度最小。

请你返回删除最多 k 个字符后，s 行程长度编码的最小长度 。

思路：
dp[i][j]表示从前i个字符中最多选择j个字符进行删除。
如果删除字符i，则此时dp[i][j] = dp[i-1][j-1].
如果保留字符i, 则此时后续尽量选择保留与字符i相同的字符。这个dp确实不好理解，但是仔细思考一下，最优解应该是包含在里面的。

*/

class Solution {  // 题解
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if (k >= s.length())
            return 0;

        vector<vector<int>> dp(s.length() + 1, vector<int>(k + 2, 0x3f3f3f3f));
        dp[0][0] = 0;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j <= k && j <= i; j++) {
                if (j < k)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);

                int same = 0, del = 0;

                for (int m = i; m <= s.length(); m++) {
                    if (s[m - 1] == s[i - 1])
                        same++;
                    else
                        del++;

                    if (j + del <= k)
                        dp[m][j + del] = min(dp[m][j + del], len(same) + 1 + dp[i - 1][j]);
                    else
                        break;
                }
            }
        }

        return dp[s.length()][k];
    }

private:
    int len(int k) {   // 连续k个相同字符转化为行程长度编码后的长度
        if (k <= 1)
            return 0;
        else if (k > 1 && k < 10)
            return 1;
        else if (k >= 10 && k < 100)
            return 2;
        else
            return 3;
    }
};