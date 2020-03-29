#include "normal.h"

/*

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();

        if (row == 0)
            return;

        int col = board[0].size();

        if (row == 1 || col == 1)
            return;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                bool edge = i == 0 || i == row - 1 || j == 0 || j == col - 1;

                if (edge && board[i][j] == 'O') {
                    dfs(board, i, j, row, col);
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')   // 这两个if顺序不能交换
                    board[i][j] = 'X';

                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] == 'X' || board[i][j] == '#')
            return;

        board[i][j] = '#';
        dfs(board, i + 1, j, row, col);
        dfs(board, i - 1, j, row, col);
        dfs(board, i, j + 1, row, col);
        dfs(board, i, j - 1, row, col);
    }
};