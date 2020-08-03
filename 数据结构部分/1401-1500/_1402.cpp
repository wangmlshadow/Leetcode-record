#include "normal.h"

/*
动态规划

一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。

一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是 time[i]*satisfaction[i] 。

请你返回做完所有菜 「喜爱时间」总和的最大值为多少。

你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。

n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3

*/

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());  // 满意值高的菜放在后面
        int curSig = 0, curAll = 0;

        for (int i = satisfaction.size() - 1; i >= 0; i--) {
            if (satisfaction[i] >= 0) {  // 满意值大于等于0的菜一定被做出来
                curSig += satisfaction[i];
                curAll += curSig;
            }
            else {
                if (curSig + satisfaction[i] > 0) {   // 判断是否可以加入这道菜
                    curSig += satisfaction[i];
                    curAll += curSig;
                }
            }
        }

        return curAll;
    }
};

/*
执行结果：通过 显示详情
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.6 MB, 在所有 C++ 提交中击败了84.38%的用户
*/