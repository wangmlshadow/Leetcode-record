#include "normal.h"

/*
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇
的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失
健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为
正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dungeon-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {  
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> dp_1(row, vector<int>(col, 0));   // 记录骑士到达每个房间所需的最小体力值
        vector<vector<int>> dp_2(row, vector<int>(col, 0));   // 记录骑士到达每个房间后所剩的体力值

        if (dungeon[0][0] < 0) {
            dp_1[0][0] = 1 - dungeon[0][0];
            dp_2[0][0] = 1;
        }            
        else {
            dp_1[0][0] = 1;// 骑士初始健康值为一个正整数
            dp_2[0][0] = 1 + dungeon[0][0];
        }           

        for (int i = 1; i < col; i++) {
            int val = dp_2[0][i - 1] + dungeon[0][i];

            if (val > 0) {
                dp_1[0][i] = dp_1[0][i - 1];
                dp_2[0][i] = val;
            }
                
            else {
                dp_1[0][i] = dp_1[0][i - 1] + 1 - val;
                dp_2[0][i] = 1;
            }                
        }

        for (int i = 1; i < row; i++) {
            int val = dp_2[i - 1][0] + dungeon[i][0];

            if (val > 0) {
                dp_1[i][0] = dp_1[i - 1][0];
                dp_2[i][0] = val;
            }
            else {
                dp_1[i][0] = dp_1[i - 1][0] + 1 - val;
                dp_2[i][0] = 1;
            }
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                // 这个思路不行
                // 从左上到右下行不通
            }
        }
    }
};


class Solution {    // 从右下到左上
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, INT_MAX));   // 记录从当前这个房间走到右下角那个房间所需的最小体力值
        // 用于初始化右下角的点
        dp[row][col - 1] = 1;  
        dp[row - 1][col] = 1;

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                int val = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, val - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};