#include "normal.h"

/*
数组

给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。

思路：比较A0 > A1 和 A0 < A1两种情况所需的操作次数

*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;

        int cnt1 = 0, cnt2 = 0;

        // A0 > A1
        int end = nums.size() - 1;
        for (int i = 1; i < end; i += 2) {
            int minVal = min(nums[i - 1], nums[i + 1]);

            if (nums[i] >= minVal)
                cnt1 += (nums[i] - minVal + 1);
        }

        if (nums.size() % 2 == 0 && nums[end] >= nums[end - 1])
            cnt1 += (nums[end] - nums[end - 1] + 1);

        // A0 < A1
        if (nums[0] >= nums[1])
            cnt2 += (nums[0] - nums[1] + 1);

        for (int i = 2; i < end; i += 2) {
            int minVal = min(nums[i - 1], nums[i + 1]);

            if (nums[i] >= minVal)
                cnt2 += (nums[i] - minVal + 1);
        }

        if (nums.size() % 2 == 1 && nums[end] >= nums[end - 1])
            cnt2 += (nums[end] - nums[end - 1] + 1);

        return min(cnt1, cnt2);
    }
};

/*
执行结果：通过显示详情
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/