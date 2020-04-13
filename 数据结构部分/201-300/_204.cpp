#include "normal.h"

/*
统计所有小于非负整数 n 的质数的数量。
*/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> helper(n, true);
        int bound = sqrt(n);

        for (int i = 2; i <= bound; i++) {
            if (helper[i]) {
                for (int j = i * i; j < n; j += i) {
                    helper[j] = false;
                }
            }
        }

        int res = 0;

        for (int i = 2; i < n; i++) {
            if (helper[i])
                res++;
        }

        return res;
    }
};