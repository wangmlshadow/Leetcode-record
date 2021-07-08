/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 回溯
// 本地测试没问题 但是leetcode报错
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        if (word.length() == 0) {
            return true;
        }
        // 标记某个位置是否被占用
        vector<vector<bool>> occupied(board.size(), vector<bool>(false, board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {// 第一个字母匹配
                    //cout << "row: " << i << " clo: " << j << endl;
                    occupied[i][j] = true;
                    if (existHead(board, i, j, occupied, word, 1)) {
                        return true;
                    }
                    occupied[i][j] = false;
                }
            }
        }
        return false;
    }

    bool existHead(vector<vector<char>>& board, int row, int clo, vector<vector<bool>>& occupied, string& word, int pos) {
        //cout << "row: " << row << " clo: " << clo << endl;
        // 找到了
        if (pos >= word.length()) {
            return true;
        }
        // 向上下左右寻找下一个满足条件的字母
        if (row - 1 >= 0 && row - 1 < board.size() && !occupied[row - 1][clo] && board[row - 1][clo] == word[pos]) {
            occupied[row - 1][clo] = true;
            if (existHead(board, row - 1, clo, occupied, word, pos + 1)) {
                return true;
            }
            occupied[row - 1][clo] = false;
        }

        if (row + 1 < board.size() && row + 1 >= 0 && !occupied[row + 1][clo] && board[row + 1][clo] == word[pos]) {
            occupied[row + 1][clo] = true;
            if (existHead(board, row + 1, clo, occupied, word, pos + 1)) {
                return true;
            }
            occupied[row + 1][clo] = false;
        }

        if (clo - 1 >= 0 && clo - 1 < board[0].size() && !occupied[row][clo - 1] && board[row][clo - 1] == word[pos]) {
            occupied[row][clo - 1] = true;
            if (existHead(board, row, clo - 1, occupied, word, pos + 1)) {
                return true;
            }
            occupied[row][clo - 1] = false;
        }

        if (clo + 1 < board[0].size() && clo + 1 >= 0 && !occupied[row][clo + 1] && board[row][clo + 1] == word[pos]) {
            occupied[row][clo + 1] = true;
            if (existHead(board, row, clo + 1, occupied, word, pos + 1)) {
                return true;
            }
            occupied[row][clo + 1] = false;
        }
        return false;
    }
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) {
            return false;
        }
        if (word.length() == 0) {
            return true;
        }
        // 不用辅助数组
        // 标记某个位置是否被占用
        //vector<vector<bool>> occupied(board.size(), vector<bool>(false, board[0].size()));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0]) {// 第一个字母匹配
                    //cout << "row: " << i << " clo: " << j << endl;
                    char temp = board[i][j];
                    board[i][j] = '#';
                    //occupied[i][j] = true;
                    if (existHead(board, i, j, word, 1)) {
                        return true;
                    }
                    //occupied[i][j] = false;
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }

    bool existHead(vector<vector<char>>& board, int row, int clo, string word, int pos) {
        //cout << "row: " << row << " clo: " << clo << endl;
        // 找到了
        if (pos >= word.length()) {
            return true;
        }
        
        // 向上下左右寻找下一个满足条件的字母
        if (row - 1 >= 0 && row - 1 < board.size() && board[row - 1][clo] == word[pos]) {
            char temp = board[row - 1][clo];
            board[row - 1][clo] = '#';
            if (existHead(board, row - 1, clo, word, pos + 1)) {
                return true;
            }
            board[row - 1][clo] = temp;
        }

        if (row + 1 < board.size() && row + 1 >= 0 && board[row + 1][clo] == word[pos]) {
            char temp = board[row + 1][clo];
            board[row + 1][clo] = '#';
            if (existHead(board, row + 1, clo, word, pos + 1)) {
                return true;
            }
            board[row + 1][clo] = temp;
        }

        if (clo - 1 >= 0 && clo - 1 < board[0].size() && board[row][clo - 1] == word[pos]) {
            char temp = board[row][clo - 1];
            board[row][clo - 1] = '#';
            if (existHead(board, row, clo - 1, word, pos + 1)) {
                return true;
            }
            board[row][clo - 1] = temp;
        }

        if (clo + 1 < board[0].size() && clo + 1 >= 0 && board[row][clo + 1] == word[pos]) {
            char temp = board[row][clo + 1];
            board[row][clo + 1] = '#';
            if (existHead(board, row, clo + 1, word, pos + 1)) {
                return true;
            }
            board[row][clo + 1] = temp;
        }
        return false;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：176 ms, 在所有 C++ 提交中击败了61.21%的用户
内存消耗：54.1 MB, 在所有 C++ 提交中击败了60.88%的用户
*/

// 还可以加一个备忘录提升速度 减少重复计算

int main() {
    Solution s;
    //vector<vector<char>> b = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    //string w = "ABCCED";
    vector<vector<char>> b = {{'a'}};
    string w = "ab";
    s.exist(b, w);
}