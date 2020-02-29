#include "normal.h"

/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            reproduce(result, nums[i]);
        }

        sort(result.begin(), result.end());   // 排序后再去除重复，取巧方式，运行比较慢
        vector<vector<int>> temp;

        for (int i = 0; i < result.size(); i++) {
            if (i == 0) {
                temp.push_back(result[i]);
                continue;
            }
                
            if (result[i - 1] != result[i])
                temp.push_back(result[i]);
        }

        return temp;
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

                while (j < type - 1 && num == cur[j]) {   // 防止重复，但是不能去除所有重复
                    j++;
                }

                cur.insert(cur.begin() + j, num);
                temp.push_back(cur);
            }
        }

        result = temp;
    }
};