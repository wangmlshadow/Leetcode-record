#include "normal.h"

/*

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水
包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四
个边均被水包围。
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();

        if (row == 0)
            return 0;

        int col = grid[0].size();
        int cnt = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ++cnt;
                    to2(i, j, grid);
                }
            }
        }

        return cnt;
    }

    void to2(int row, int col, vector<vector<char>>& grid) {   // 避免重复 将已经访问过的陆地变为2
        if (grid[row][col] == '0' || grid[row][col] == '2')
            return;

        grid[row][col] = '2';

        if (row > 0)
            to2(row - 1, col, grid);

        if (row < grid.size() - 1)
            to2(row + 1, col, grid);

        if (col > 0)
            to2(row, col - 1, grid);

        if (col < grid[0].size() - 1)
            to2(row, col + 1, grid);
    }
};