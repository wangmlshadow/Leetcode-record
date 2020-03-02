#include "normal.h"

/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool sign = false;   // 标记newInterval是否已经插入完成

        for (int i = 0; i < intervals.size(); i++) {
            if (sign)
                result.push_back(intervals[i]);
            else {
                if (intervals[i][0] > newInterval[1]) {
                    result.push_back(newInterval);
                    sign = true;
                    result.push_back(intervals[i]);
                }
                else if (intervals[i][1] < newInterval[0]) {
                    result.push_back(intervals[i]);
                }
                else {
                    newInterval[0] = min(intervals[i][0], newInterval[0]);
                    newInterval[1] = max(intervals[i][1], newInterval[1]);
                }
            }           
        }

        if (!sign)
            result.push_back(newInterval);

        return result;
    }
};