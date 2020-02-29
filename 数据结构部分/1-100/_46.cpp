#include "normal.h"

/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
*/

class Solution {  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            reproduce(result, nums[i]);
        }

        return result;
    }

    void reproduce(vector<vector<int>>& result, int num) {     // 在给定的一段数字中再插入一个数字，将插入后的所有结果通过result返回
        if (result.empty()) {
            result.push_back({ num });
            return;
        }
        
        int type = result[0].size() + 1;     // 长为n的数字段中插入一个数字，可以产生n+1种结果
        vector<vector<int>> temp;

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < type; j++) {
                vector<int> cur = result[i];
                cur.insert(cur.begin() + j, num);
                temp.push_back(cur);
            }
        }

        result = temp;
    }
};      // 运行结果显示这个很快