#include "normal.h"

/*
数组

给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。
（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）

从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 并满足下列条件之一：

0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
0 <= j < j + M - 1 < i < i + L - 1 < A.length.

思路：将所有可能连续子数组和使用数组存储下来，他们所在数组中的位置可以表示子数组在A中的位置，然后遍历所有可能

*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sumL;  // 分别为长度为L、M的连续子数组内所有元素之和，sumL、sumM中第i个元素表示起始位置为i的连续长度L、M的子数组和
        vector<int> sumM;
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < A.size(); i++) {
            if (i < L - 1)
                sum1 += A[i];
            else if (i == L - 1) {
                sum1 += A[i];
                sumL.push_back(sum1);
            }
            else {
                sum1 += A[i] - A[i - L];
                sumL.push_back(sum1);
            }
            
            if (i < M - 1)
                sum2 += A[i];
            else if (i == M - 1) {
                sum2 += A[i];
                sumM.push_back(sum2);
            }
            else {
                sum2 += A[i] - A[i - M];
                sumM.push_back(sum2);
            }
        }

        int res = INT_MIN;

        for (int i = 0; i < sumL.size(); i++) {
            for (int j = 0; j < sumM.size(); j++) {  // 判断是否重叠
                if (i >= j + M || j >= i + L) {
                    res = max(res, sumL[i] + sumM[j]);
                }
            }
        }

        return res;
    }
};


/*
执行结果：通过 显示详情
执行用时：32 ms, 在所有 C++ 提交中击败了13.39%的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/