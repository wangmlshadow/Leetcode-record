#include "normal.h"

/*
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为
活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循
以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则
同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        rows = board.size();
        cols = rows == 0 ? 0 : board[0].size();

        if (rows == 0 || cols == 0)
            return;

        // 2表示 从死到活
        // 3表示 从活到死

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int n = getLife(i, j, board);

                if (board[i][j] == 0) {
                    if (n == 3)
                        board[i][j] = 2;
                }
                else {
                    if (n < 2 || n > 3)
                        board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 1;

                if (board[i][j] == 3)
                    board[i][j] = 0;
            }
        }
    }
private:
    int rows;
    int cols;

    int getLife(int row, int col, vector<vector<int>>& board) {
        int cnt = 0;

        if (row - 1 >= 0 && col - 1 >= 0)
            if (board[row - 1][col - 1] == 1 || board[row - 1][col - 1] == 3)
                cnt++;

        if (row - 1 >= 0)
            if (board[row - 1][col] == 1 || board[row - 1][col] == 3)
                cnt++;

        if (row - 1 >= 0 && col + 1 < cols)
            if (board[row - 1][col + 1] == 1 || board[row - 1][col + 1] == 3)
                cnt++;

        if (col - 1 >= 0)
            if (board[row][col - 1] == 1 || board[row][col - 1] == 3)
            cnt++;

        if (col + 1 < cols)
            if (board[row][col + 1] == 1 || board[row][col + 1] == 3)
                cnt++;

        if (row + 1 < rows && col - 1 >= 0)
            if (board[row + 1][col - 1] == 1 || board[row + 1][col - 1] == 3)
                cnt++;

        if (row + 1 < rows)
            if (board[row + 1][col] == 1 || board[row + 1][col] == 3)
                cnt++;

        if (row + 1 < rows && col + 1 < cols)
            if (board[row + 1][col + 1] == 1 || board[row + 1][col + 1] == 3)
                cnt++;

        return cnt;
    }
}; 