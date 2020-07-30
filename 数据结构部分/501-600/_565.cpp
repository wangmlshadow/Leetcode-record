#include "normal.h"

/*
数组

索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

思路：1.根据题目要求暴力求解，结果超时
      2.改进第一种方法，使用数组标记已经遍历过的环
      3.直接修改原数组，不需要额外内存
*/

class Solution {   // 超时 第854个样例不通过
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> have(nums.size(), 0);
            int cnt = 0, j = i;

            while (have[j] == 0) {
                have[j] = 1;
                cnt++;
                j = nums[j];
            }

            res = max(res, cnt);
        }

        return res;
    }
};

class Solution {   // 优化 去除过多的重复测试
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;
        vector<int> have(nums.size(), 0);   // S是由nums中各个元素组成的一个环，从环的任何一个点都可以遍历整个环
                                            // 因此与上述代码相比，将have放到外面，避免重复遍历同一个环

        for (int i = 0; i < nums.size(); i++) {
            if (have[i] != 0)
                continue;

            int cnt = 0, j = i;

            while (have[j] == 0) {
                have[j] = 1;
                cnt++;
                j = nums[j];
            }

            res = max(res, cnt);
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：60 ms, 在所有 C++ 提交中击败了19.08%的用户
内存消耗：29.7 MB, 在所有 C++ 提交中击败了25.00%的用户
*/


class Solution {   
public:
    int arrayNesting(vector<int>& nums) {
        int res = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums.size())
                continue;

            int cnt = 0, j = i, temp;

            while (nums[j] != nums.size()) {
                temp = j;
                cnt++;
                j = nums[j];
                nums[temp] = nums.size();
            }

            res = max(res, cnt);
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：32 ms, 在所有 C++ 提交中击败了91.60%的用户
内存消耗：29.4 MB, 在所有 C++ 提交中击败了25.00%的用户
*/