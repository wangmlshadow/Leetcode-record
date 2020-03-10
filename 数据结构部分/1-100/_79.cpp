#include "normal.h"

/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {    // 通过了，但是挺慢的，backtrack()可以改进，等第二遍看题目再改
public:
    bool exist(vector<vector<char>>& board, string word) {
        sign = false;
        m = board.size();
        len = word.length();

        if (m == 0)
            return len == 0;

        n = board[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        backtrack(0, 0, used, 0, word, board);

        return sign;
    }

private:
    bool sign;
    int m;
    int n;
    int len;

    void backtrack(int row, int col, vector<vector<bool>> used, int pos, string& word, vector<vector<char>>& board) {
        if (sign)
            return;

        if (pos == 0) {
            for (int i = row; i < m; i++) {
                for (int j = col; j < n; j++) {
                    if (word[pos] == board[i][j]) {
                        if (pos == word.length() - 1) {
                            sign = true;
                            return;
                        }

                        vector<vector<bool>> temp = used;
                        temp[i][j] = true;
                        backtrack(i, j, temp, pos + 1, word, board);
                    }
                }
            }
        }
        else {
            // 上下左右
            if (row > 0 && used[row - 1][col] == false && word[pos] == board[row - 1][col]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row - 1][col] = true;
                backtrack(row - 1, col, temp, pos + 1, word, board);
            }

            if (row < m - 1 && used[row + 1][col] == false && word[pos] == board[row + 1][col]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row + 1][col] = true;
                backtrack(row + 1, col, temp, pos + 1, word, board);
            }

            if (col > 0 && used[row][col - 1] == false && word[pos] == board[row][col - 1]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row][col - 1] = true;
                backtrack(row, col - 1, temp, pos + 1, word, board);
            }

            if (col < n - 1 && used[row][col + 1] == false && word[pos] == board[row][col + 1]) {
                if (pos == word.length() - 1) {
                    sign = true;
                    return;
                }

                vector<vector<bool>> temp = used;
                temp[row][col + 1] = true;
                backtrack(row, col + 1, temp, pos + 1, word, board);
            }
        }
    }
};