#include "normal.h"

/*
井字游戏 数组

设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
"X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

1 <= board.length == board[i].length <= 100
输入一定遵循井字棋规则

思路：
遍历 正对角线 副对角线 每一行 每一列 
*/

class Solution {
public:
    string tictactoe(vector<string>& board) {
        int n = board.size();
        int i = 0;
        string res;

        for (; i < n; i++) {  // 遍历正对角线元素
            if (board[i][i] == ' ')
                break;

            if (i != 0 && board[i][i] != board[i - 1][i - 1])
                break;
        }

        if (i == n) {
            res.push_back(board[0][0]);
            return res;
        }
        else
            i = 0;

        for (; i < n; i++) {  // 遍历副对角线元素
            if (board[i][n - 1 - i] == ' ')
                break;

            if (i != 0 && board[i][n - 1 - i] != board[i - 1][n - i])
                break;
        }

        if (i == n) {
            res.push_back(board[0][n - 1]);
            return res;
        }
        else
            i = 0;

        // 第j行 第j列
        for (int j = 0; j < n; j++) {
            for (i = 0; i < n; i++) {
                if (board[j][i] == ' ')
                    break;

                if (i != 0 && board[j][i] != board[j][i - 1])
                    break;
            }

            if (i == n) {
                res.push_back(board[j][0]);
                return res;
            }

            for (i = 0; i < n; i++) {
                if (board[i][j] == ' ')
                    break;

                if (i != 0 && board[i][j] != board[i - 1][j])
                    break;
            }

            if (i == n) {
                res.push_back(board[0][j]);
                return res;
            }
        }

        for (int j = 0; j < n; j++) {   // 仍有空格 游戏未结束
            for (int k = 0; k < n; k++) {
                if (board[j][k] == ' ')
                    return "Pending";
            }
        }
    
        return "Draw";  // 平局
    }
};

/*
执行结果：
通过
显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了97.65%的用户
内存消耗：8.2 MB, 在所有 C++ 提交中击败了100.00%的用户
*/