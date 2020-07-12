#include "normal.h"

/*
高度检查器     数组

学校在拍年度纪念照时，一般要求学生按照 非递减 的高度顺序排列。

请你返回能让所有学生以 非递减 高度排列的最小必要移动人数。

注意，当一组学生被选中时，他们之间可以以任何可能的方式重新排序，而未被选中的学生应该保持不动。

 思路：将元素组复制一个副本，将副本排序，再与原数组比较，观察多少个位置的数不同

*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights);
        sort(sorted.begin(), sorted.end());
        int res = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i])
                res++;
        }

        return res;
    }
};

/*
执行结果：通过 显示详情
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/