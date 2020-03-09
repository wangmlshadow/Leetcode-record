#include "normal.h"

/*

给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int start = 0;
        vector<int> result;
        solution(nums, result, 0);
        return results;
    }

private:
    vector<vector<int>> results;

    void solution(vector<int>& nums, vector<int> result, int start) {
        results.push_back(result);

        for (int i = start; i < nums.size(); i++) {
            vector<int> temp = result;
            temp.push_back(nums[i]);
            solution(nums, temp, i + 1);
        }
    }
};