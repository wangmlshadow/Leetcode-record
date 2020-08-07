#include "normal.h"

/*
二指输入法定制键盘在 XY 平面上的布局如上图所示，其中每个大写英文字母都位于某个坐标处，例如
字母 A 位于坐标 (0,0)，字母 B 位于坐标 (0,1)，字母 P 位于坐标 (2,3) 且字母 Z 位于坐标 (4,1)。

给你一个待输入字符串 word，请你计算并返回在仅使用两根手指的情况下，键入该字符串需要的最小移
动总距离。坐标 (x1,y1) 和 (x2,y2) 之间的距离是 |x1 - x2| + |y1 - y2|。 

注意，两根手指的起始位置是零代价的，不计入移动总距离。你的两根手指的起始位置也不必从首字母或
者前两个字母开始。

2 <= word.length <= 300
每个 word[i] 都是一个大写英文字母。
*/

class Solution {
public:
    int minimumDistance(string word) {
        if (word.length() <= 2)
            return 0;

        vector<vector<int>> dp(26, vector<int>(26, 0));

        for (int i = word.size() - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++)
                dp[j][word[i] - 'A'] = min(distance(j, word[i + 1] - 'A') + dp[word[i] - 'A'][word[i + 1] - 'A'], distance(word[i] - 'A', word[i + 1] - 'A') + dp[j][word[i + 1] - 'A']);
        }

        int res = INT_MAX;

        for (int i = 0; i < 26; i++) {
            res = min(res, dp[i][word[0] - 'A']);
        }

        return res;
    }

    int distance(int i, int j) {
        int x1 = i / 6, y1 = i % 6;
        int x2 = j / 6, y2 = j % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
};