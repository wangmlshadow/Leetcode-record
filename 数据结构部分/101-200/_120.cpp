#include "normal.h"

/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {   // 类似于杨辉三角的形成 将triangle某行某元素加上它上一行两个相邻元素中的最小值
        int size = triangle.size();

        if (size == 0)
            return 0;

        for (int i = 1; i < size; i++) {
            int size_2 = triangle[i].size() - 1;

            for (int j = 0; j <= size_2; j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][0];
                else if (j == size_2)
                    triangle[i][j] += triangle[i - 1][i - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);                   
            }
        }
        
        int min = triangle[size - 1][0];

        for (int i = 1; i < triangle[size - 1].size(); i++) {
            if (min > triangle[size - 1][i])
                min = triangle[size - 1][i];
        }

        return min;
    }
};