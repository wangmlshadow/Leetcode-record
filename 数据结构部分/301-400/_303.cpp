#include "normal.h"

/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int sum = 0;

        for (auto num : nums) {
            sum += num;
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];

        return sums[j] - sums[i - 1];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */