#include "normal.h"

/*
动态规划

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
*/

class Solution {   // 超时了，递归
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;

        return solution(1, n);
    }

private:
    int solution(int start, int end) {
        int cnt = 0;
        if (start >= end)
            return 1;

        for (int i = start; i <= end; i++) {
            int left = solution(start, i - 1);
            int right = solution(i + 1, end);

            cnt += left * right;
        }

        return cnt;
    }
};


class Solution {    // 动态规划
public:
    int numTrees(int n) {
        if (n == 0)
            return 0;

        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                res[i] += res[j - 1] * res[i - j];     // 左边 j-1个节点 右边 i-j个节点（二叉搜索树7-10和1-4种类是一样的）
            }
        }

        return res[n];
    } 
};
