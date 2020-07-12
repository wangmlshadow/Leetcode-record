#include "normal.h"

/*
剑指 Offer 53 - II. 0～n-1中缺失的数字    数组
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

思路：类似于二分查找 先判断是否存在0 若0不存在 返回0
      若存在 在缺少的数字之前，所有数组元素等于数组下标，在缺少的元素之后，所有数组元素大于下标值1位
      如下代码 返回left left之前的数字都不缺少

*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 是否有0
        if (nums[0] != 0)
            return 0;

        // 0存在 在缺少的数字之前，所有数组元素等于数组下标，在缺少的元素之后，所有数组元素大于下标值1位

        int left = 0, right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;

            if (mid == nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }

        return left;
    }
};

/*
执行结果：通过 显示详情
执行用时：64 ms, 在所有 C++ 提交中击败了7.54%的用户
内存消耗：17.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/