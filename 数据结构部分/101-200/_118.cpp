#include "normal.h"

/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if (numRows == 0)
            return res;

        res.push_back({ 1 });

        for (int i = 1; i < numRows; i++) {
            vector<int> temp;

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    temp.push_back(1);
                    continue;
                }

                temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }

            res.push_back(temp);
        }

        return res;
    }
}; // 运行速度和空间使用都超过100%