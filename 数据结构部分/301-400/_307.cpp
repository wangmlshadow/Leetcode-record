#include "normal.h"

/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

update(i, val) 函数可以通过将下标为 i 的数值更新为 val，从而对数列进行修改。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-mutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
            return;

        sums.push_back(nums[0]);

        for (int i = 1; i < size; i++)
            sums.push_back(nums[i] + *sums.rbegin());
    }

    void update(int i, int val) {
        int pre = sums[i] - (i > 0 ? sums[i - 1] : 0);

        for (int j = i; j < sums.size(); j++) {
            sums[j] = sums[j] - pre + val;
        }
    }

    int sumRange(int i, int j) {
        return sums[j] - ((i > 0) ? sums[i - 1] : 0);
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */