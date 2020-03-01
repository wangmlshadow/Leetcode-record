#include "normal.h"

/*
给定一个整数 n，返回 n 皇后不同的解决方案的数量
*/

class Solution {    // 回溯法，在上一题解答中就行修改
private:
    //vector<vector<string>> result;   // 最后结果
    // 分别标准哪些行、主对角线、副对角线会被攻击
    vector<int> rows;
    vector<int> leadingDiag;
    vector<int> countreDiag;
    // 皇后被放置的位置
    vector<int> queen;
    int n;
    int result;

    void backtrack(int row) {
        if (row >= n)
            return;

        // 在row行的各列尝试放置
        for (int col = 0; col < n; col++) {
            if (isNotUnderAttack(row, col)) {
                placeQueen(row, col);

                if (row == n - 1)   // 放置了最后一个棋子
                    addSolution();
                else
                    backtrack(row + 1);

                removeQueen(row, col);   // 撤销这一步
            }
        }
    }

    bool isNotUnderAttack(int row, int col) {
        int res = rows[col] + leadingDiag[row - col + n - 1] + countreDiag[row + col];

        return res == 0;
    }

    void placeQueen(int row, int col) {
        queen[row] = col;
        rows[col] = 1;
        leadingDiag[row - col + n - 1] = 1;
        countreDiag[row + col] = 1;
    }

    void removeQueen(int row, int col) {
        queen[row] = 0;
        rows[col] = 0;
        leadingDiag[row - col + n - 1] = 0;
        countreDiag[row + col] = 0;
    }

    void addSolution() {
        result ++;
    }

public:
    int totalNQueens(int n) {
        rows = vector<int>(n, 0);
        leadingDiag = vector<int>(2 * n - 1, 0);
        countreDiag = vector<int>(2 * n - 1, 0);
        queen = vector<int>(n, 0);
        this->n = n;
        result = 0;
        backtrack(0);

        return result;
    }
};