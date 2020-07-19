#include "normal.h"

/*
数组

给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

思路：一个数的高位数字越大，这个数也就越大，将num每一位数字分解存储在数组中，排序，比较，得到所需被交换的两个位置

注意：考虑到可能多个位置的数相等，越低位的较大数字被交换到越高位，最后结果越大
*/

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;  // 将num每一位的数字拆开存储在nums中   个位到最高位
        int temp = num;

        while (temp != 0) {
            nums.push_back(temp % 10);
            temp /= 10;
        }

        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());   // 从小到大排序

        int pos = nums.size() - 1;   // 最终被交换的位置

        while (pos > 0 && nums[pos] == sorted[pos])
            pos--;

        if (pos < 0)
            return num;

        int another = 0;

        while (nums[another] != sorted[pos])
            another++;

        nums[another] = nums[pos];
        nums[pos] = sorted[pos];

        int res = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
            res = res * 10 + nums[i];

        return res;
    }
};

/*
执行结果通过 显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了30.10%的用户
内存消耗：6 MB, 在所有 C++ 提交中击败了100.00%的用户
*/