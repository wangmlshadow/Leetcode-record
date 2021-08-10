/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = INT_MAX;
        int cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (res == nums[i]) {
                ++cnt;
            }
            else {
                if (cnt == 0) {
                    res = nums[i];
                }
                else {
                    --cnt;
                }
            }
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 C++ 提交中击败了96.43%的用户
内存消耗：18.3 MB, 在所有 C++ 提交中击败了60.43%的用户
*/