#include "normal.h"

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int cnt = 1;
            while (i < size - 1 && nums[i + 1] == nums[i]) {
                i++;
                cnt++;
            }
            Append(result, nums[i], cnt);
        }

        
        return result;
    }

    void Append(vector<vector<int>>& result, int n, int cnt) {
        int size = result.size();

        for (int i = 0; i < size; i++) {
            vector<int> temp = result[i];
            
            for (int j = 0; j < cnt; j++) {
                temp.push_back(n);
                result.push_back(temp);
            }
        }
    }
};