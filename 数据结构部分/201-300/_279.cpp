#include "normal.h"

/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要
让组成和的完全平方数的个数最少。
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n + 1, INT_MAX);
        res[0] = 0;
        int maxSq = sqrt(n) + 1;
        vector<int> sq(maxSq);

        for (int i = 1; i < maxSq; i++)
            sq[i] = i * i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < maxSq; j++) {
                if (i < sq[j])
                    break;

                res[i] = min(res[i], res[i - sq[j]] + 1);
            }
        }

        return res[n];
    }
};