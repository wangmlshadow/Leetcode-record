#include "normal.h"

/*
动态规划

你正在安装一个广告牌，并希望它高度最大。这块广告牌将有两个钢制支架，两边各一个。每个钢支架的高度必须相等。

你有一堆可以焊接在一起的钢筋 rods。举个例子，如果钢筋的长度为 1、2 和 3，则可以将它们焊接在一起形成长度为 6 的支架。

返回广告牌的最大可能安装高度。如果没法安装广告牌，请返回 0。

0 <= rods.length <= 20
1 <= rods[i] <= 1000
钢筋的长度总和最多为 5000

*/

class Solution { 
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> minDrop(sum + 1, INT_MAX);
        vector<bool> canget(sum + 1, false);
        minDrop[0] = 0;
        canget[0] = true;

        for (auto i : rods) {
            for (int j = sum; j >= 0; j--) {
                if (j - i >= 0 && canget[j - i]) {
                    canget[j] = true;
                    minDrop[j] = min(minDrop[j], minDrop[j - i] + i);
                }

                if (j - 2 * i >= 0 && canget[j - 2 * i]) {
                    canget[j] = true;
                    minDrop[j] = min(minDrop[j], minDrop[j - 2 * i]);
                }
            }
        }

        return (sum - minDrop[sum]) / 2;
    }
};