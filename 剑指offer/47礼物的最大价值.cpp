/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向
右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
*/

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() ==0) {
            return 0;
        }

        // 动态规划
        // 到达位置为(i, j)可以得到的最大礼物 = max((i - 1, j), (i, j - 1)) + (i, j)
        vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));

        // 初始化
        for (int i = 0; i < grid[0].size(); ++i) {
            if (i == 0) {
                res[0][i] = grid[0][0];
            }
            else {
                res[0][i] = grid[0][i] + res[0][i - 1];
            }
        }

        for (int i = 1; i < grid.size(); ++i) {
            res[i][0] = grid[i][0] + res[i - 1][0];
        }

        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                res[i][j] = grid[i][j] + max(res[i - 1][j], res[i][j - 1]);
            }
        }

        return res[grid.size() - 1][grid[0].size() - 1];
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了77.25%的用户
内存消耗：9.2 MB, 在所有 C++ 提交中击败了33.96%的用户
*/