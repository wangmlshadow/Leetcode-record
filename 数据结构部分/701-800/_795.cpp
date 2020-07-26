#include "normal.h"

/*
数组 

给定一个元素都是正整数的数组A ，正整数 L 以及 R (L <= R)。

求连续、非空且其中最大元素满足大于等于L 小于等于R的子数组个数。

思路：1.依次判断由i开头的子数组是否满足条件
      2.滑动窗口   没有考虑到所有情况 出错

*/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int left = 0, right = -1, res = 0, maxVal = INT_MIN;

        for (int i = 0; i < A.size(); i++) {
            bool sign = false;  // 判断子数组i-j是否满足条件

            for (int j = i; j < A.size(); j++) {
                if (A[j] > R)
                    break;
                
                sign = sign || A[j] >= L;

                if (sign)
                    res++;
            }
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：112 ms, 在所有 C++ 提交中击败了21.22%的用户
内存消耗：30.6 MB, 在所有 C++ 提交中击败了50.00%的用户
*/

