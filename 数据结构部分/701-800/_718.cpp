#include "normal.h"

/*
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                //dp[i][j] = (A[i] == B[j]) ? dp[i + 1][j + 1] + 1 : 0;  // 超过29/33

                if (A[i] == B[j])  // 超过43/33
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};