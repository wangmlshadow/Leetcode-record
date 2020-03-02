#include "normal.h"

/*
给出一个区间的集合，请合并所有重叠的区间。
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int size = intervals.size();

        if (size == 0)
            return result;

        result.push_back(intervals[0]);

        for (int i = 1; i < size; i++) {
            vector<int> cur = intervals[i];
            vector<vector<int>> temp;

            for (int j = result.size() - 1; j >= 0; j--) {
                if (result[j][0] > cur[1] || result[j][1] < cur[0]) {
                    temp.push_back(result[j]);
                    continue;
                }
                else {
                    cur[0] = min(result[j][0], cur[0]);
                    cur[1] = max(result[j][1], cur[1]);
                }
            }
            temp.push_back(cur);
            result = temp;
        }

        return result;
    }
};