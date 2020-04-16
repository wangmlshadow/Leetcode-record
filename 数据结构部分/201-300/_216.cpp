#include "normal.h"

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        getRes({}, n, k, min(9, n));       
        return res;
    }

    void getRes(vector<int> nums, int n, int k, int num) {
        if (n == 0 && k == 0) {
            res.push_back(nums);
            return;
        }

        if (n == 0 || k == 0)
            return;

        if (num <= 0 || n < 0)
            return;

        if (n > 0) {
            nums.push_back(num);
            getRes(nums, n - num, k - 1, num - 1);
            nums.pop_back();
        }

        getRes(nums, n, k, num - 1);
    }

private:
    vector<vector<int>> res;
};


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> none;
        getRes(none, n, k, min(9, n));
        return res;
    }

    void getRes(vector<int>& nums, int n, int k, int num) {    // nums使用引用传递比传值快了很多
        if (n == 0 && k == 0) {
            res.push_back(nums);
            return;
        }

        if (n == 0 || k == 0)
            return;

        if (num <= 0 || n < 0)
            return;

        if (n > 0) {
            nums.push_back(num);
            getRes(nums, n - num, k - 1, num - 1);
            nums.pop_back();
        }

        getRes(nums, n, k, num - 1);
    }

private:
    vector<vector<int>> res;
};