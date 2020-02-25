#include "normal.h"

/*
编写一个程序，通过已填充的空格来解决数独问题。
*/

class Solution {     // 思路见官方解答
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool suc = false;
        vector<vector<int>> row(9, vector<int>(10, 0));   // 行
        vector<vector<int>> col(9, vector<int>(10, 0));   // 列
        vector<vector<int>> box(9, vector<int>(10, 0));   // 分块

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    placeNumber(num, i, j, row, col, box, board);
                }
            }
        }
        backtrack(suc, 0, 0, row, col, box, board);
    }

    bool couldPlace(int num, int row_id, int col_id, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box) {
        int box_id = (row_id / 3) * 3 + col_id / 3;

        return (row[row_id][num] + col[col_id][num] + box[box_id][num] == 0);
    }

    void placeNumber(int num, int row_id, int col_id, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, vector<vector<char>>& board) {
        int box_id = (row_id / 3) * 3 + col_id / 3;

        row[row_id][num]++;
        col[col_id][num]++;
        box[box_id][num]++;

        board[row_id][col_id] = '0' + num;
    }

    void removeNumber(int num, int row_id, int col_id, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, vector<vector<char>>& board) {
        int box_id = (row_id / 3) * 3 + col_id / 3;

        row[row_id][num]--;
        col[col_id][num]--;
        box[box_id][num]--;

        board[row_id][col_id] = '.';
    }

    void placeNextNumber(bool& suc, int row_id, int col_id, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, vector<vector<char>>& board) {
        if (row_id == 8 && col_id == 8)
            suc = true;
        else {
            if (col_id == 8)
                backtrack(suc, row_id + 1, 0, row, col, box, board);
            else
                backtrack(suc, row_id, col_id + 1, row, col, box, board);
        }
    }

    void backtrack(bool& suc, int row_id, int col_id, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box, vector<vector<char>>& board) {
        if (board[row_id][col_id] == '.') {
            for (int num = 1; num <= 9; num++) {
                if (couldPlace(num, row_id, col_id, row, col, box)) {
                    placeNumber(num, row_id, col_id, row, col, box, board);
                    placeNextNumber(suc, row_id, col_id, row, col, box, board);

                    if (!suc)
                        removeNumber(num, row_id, col_id, row, col, box, board);
                }
            }
        }
        else
            placeNextNumber(suc, row_id, col_id, row, col, box, board);       
    }
};