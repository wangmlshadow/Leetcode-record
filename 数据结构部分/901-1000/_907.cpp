#include "normal.h"

/*
数组

给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。

由于答案可能很大，因此返回答案模 10^9 + 7。

思路：1.暴力求解，超时
*/

class Solution {  // 第91个测试用例超时
public:
    int sumSubarrayMins(vector<int>& A) {
        long long res = 0;

        for (int i = 0; i < A.size(); i++) {
            int minV = INT_MAX;
            for (int j = i; j < A.size(); j++) {
                minV = min(minV, A[j]);
                res += minV;
            }
        }

        return res % 1000000007;
    }
};

class Solution {    // 题解
public:
    int sumSubarrayMins(vector<int>& A) {
        const long M = 1e9 + 7;
        long long res = 0;
        stack<int> s;
        vector<long> sums(A.size(), 0);

        for (int i = 0; i < A.size(); i++) {
            while (!s.empty() && A[s.top()] >= A[i])
                s.pop();

            if (s.empty())
                sums[i] = A[i] * (i + 1);
            else
                sums[i] = sums[s.top()] + A[i] * (i - s.top());

            sums[i] %= M;
            s.push(i);
        }

        for (int i = 0; i < A.size(); i++) {
            res += sums[i];
            res %= M;
        }

        return res;
    }
};