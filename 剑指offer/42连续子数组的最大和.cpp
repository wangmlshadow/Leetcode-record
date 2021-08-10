/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的
最大值。

要求时间复杂度为O(n)。
*/

// dp而不是滑动窗口
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], pre = 0;// pre表示每一个以nums[i]作为结尾的和最大的子数组

        for (auto &num : nums) {
            pre = max(pre + num, num);
            res = max(res, pre);
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了99.81%的用户
内存消耗：22.3 MB, 在所有 C++ 提交中击败了76.67%的用户
*/