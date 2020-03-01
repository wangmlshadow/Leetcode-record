#include "normal.h"

/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
*/

class Solution {    // 回溯法，见官方题解
private:
    vector<vector<string>> result;   // 最后结果
    // 分别标准哪些行、主对角线、副对角线会被攻击
    vector<int> rows;
    vector<int> leadingDiag;
    vector<int> countreDiag;
    // 皇后被放置的位置
    vector<int> queen;
    int n;

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
        vector<string> solution;

        for (int i = 0; i < n; i++) {
            int col = queen[i];
            string temp;

            for (int j = 0; j < col; j++) {
                temp.push_back('.');
            }

            temp.push_back('Q');

            for (int j = 0; j < n - 1 - col; j++) {
                temp.push_back('.');
            }

            solution.push_back(temp);
        }

        result.push_back(solution);
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        rows = vector<int>(n, 0);
        leadingDiag = vector<int>(2 * n - 1, 0);
        countreDiag = vector<int>(2 * n - 1, 0);
        queen = vector<int>(n, 0);
        this->n = n;
        backtrack(0);

        return result;
    }
};