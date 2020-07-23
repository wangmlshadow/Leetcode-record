#include "normal.h"

/*
数组 

给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

以任意顺序返回这两个数字均可。

思路; 排序 1-》n 按位置依次遍历验证是否存在 但是排序后时间复杂度达不到O(N)

题解中：1.求和 2.异或 3.原地Hash 
*/

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> res;
        sort(nums.begin(), nums.end());
        int cur = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cur)
                cur++;
            else {
                while (cur < nums[i])
                    res.push_back(cur++);
                cur++;
            }
        }

        while (cur <= n)
            res.push_back(cur++);

        return res;
    }
};


/*
执行结果：通过 显示详情
执行用时：120 ms, 在所有 C++ 提交中击败了10.97%的用户
内存消耗：22.8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/