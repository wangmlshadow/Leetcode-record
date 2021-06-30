/*
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但
不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
2 <= n <= 100000
*/

#include <iostream>
#include <vector>
using namespace std;

// 使用空间换时间的方式
// 下面直接用的vector 当然也可以用map 道理都是一样的
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> has(nums.size(), false);
        for (int i = 0; i < nums.size(); ++i) {
            if (!has[nums[i]]) {
                has[nums[i]] = true;
            }
            else {
                return nums[i];
            }
        }
        return -1;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：52 ms, 在所有 C++ 提交中击败了50.15%的用户
内存消耗：22.4 MB, 在所有 C++ 提交中击败了81.26%的用户
*/


