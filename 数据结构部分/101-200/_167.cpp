#include "normal.h"

/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// 最简单的直接测试所有可能两个数的和
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res(2, 0);
        int right = numbers.size() - 1;
        int left = 0;

        //while (right > left && numbers[right] > target)
        //    right--;

        for (int i = left; i < right; i++) {
            for (int j = i + 1; j <= right; j++) {
                while (j < right && numbers[j] == numbers[j + 1])  // 跳过重复的数字 避免超时
                    j++;

                if (numbers[i] + numbers[j] == target) {
                    res[0] = i + 1;
                    res[1] = j + 1;
                    return res;
                }
            }

            while (i + 1 < right && numbers[i] == numbers[i + 1])
                i++;
        }

        return res;
    }
};

