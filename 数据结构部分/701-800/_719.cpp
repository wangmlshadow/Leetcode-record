#include "normal.h"

/*
数组

给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
*/

class Solution {  // 数对之间距离 距离对应的数对个数    二分  寻找k
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = *nums.rbegin() - *nums.begin();  // 数对之间距离的最大值和最小值

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0, left = 0;

            for (int right = 0; right < nums.size(); right++) {
                while (nums[right] - nums[left] > mid)
                    left++;

                count += right - left;  // 距离小于
            }

            if (count >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};