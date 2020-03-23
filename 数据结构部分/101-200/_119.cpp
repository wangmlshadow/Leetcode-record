#include "normal.h"

/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {   // 此时最开始行从第0行开始
        vector<int> res;

        res.push_back(1);
        rowIndex++;
        for (int i = 1; i < rowIndex; i++) {
            vector<int> temp;

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(res[j - 1] + res[j]);
                }
            }

            res = temp;
        }

        return res;
    }
};  // 运行速度和空间使用都超过100%