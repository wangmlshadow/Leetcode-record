#include "normal.h"

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

class Solution {    // 比较慢
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = 0;
        int size = heights.size();

        for (int i = 0; i < size; i++) {
            int min = heights[i];

            for (int j = i; j < size; j++) {
                if (min > heights[j])
                    min = heights[j];

                if (max < (j - i + 1) * min)
                    max = (j - i + 1) * min;
            }
        }

        return max;
    }
};



class Solution {    // 分治法超时了？暴力法都没超时（遇到测试用例为N个1）
public:
    int largestRectangleArea(vector<int>& heights) {
        return solution(0, heights.size() - 1, heights);
    }

    int solution(int start, int end, vector<int>& heights) {
        if (start > end)
            return 0;

        if (start == end)
            return heights[start];

        int min = start;

        for (int i = start + 1; i <= end; i++) {
            if (heights[min] > heights[i])
                min = i;
        }

        return max((end - start + 1) * heights[min], max(solution(start, min - 1, heights), solution(min + 1, end, heights)));
    }
};


class Solution {    // 分治法优化，优化方式是在题解中看到的一个也遇到此问题的回答
public:
    int largestRectangleArea(vector<int>& heights) {
        return solution(0, heights.size() - 1, heights);
    }

    int solution(int start, int end, vector<int>& heights) {
        if (start > end)
            return 0;

        if (start == end)
            return heights[start];

        int min = start;

        for (int i = start + 1; i <= end; i++) {
            if (heights[min] > heights[i])
                min = i;
        }

        int left = min - 1;
        int right = min + 1;

        while (left >= start && heights[left] == heights[min])
            left--;

        while (right <= end && heights[right] == heights[min])
            right++;

        return max((end - start + 1) * heights[min], max(solution(start, left, heights), solution(right, end, heights)));
    }
};   // 分治法还是不快啊




