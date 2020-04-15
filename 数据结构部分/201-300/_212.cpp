#include "normal.h"

/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 不用前缀树试试 超时
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();

        if (row == 0)
            return {};

        int col = board[0].size();
        int cnt = words.size();
        vector<string> res;

        for (int k = 0; k < cnt; k++) {            
            bool sign = false;

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (board[i][j] == words[k][0]) {
                        vector<vector<bool>> used(row, vector<bool>(col, false));
                        sign = sign || search(board, used, words[k], i, j);
                    }

                    if (sign) {
                        break;
                    }
                }

                if (sign) {
                    break;
                }
            }
            
            if (sign)
                res.push_back(words[k]);
        }

        return res;
    }

    bool search(vector<vector<char>>& board, vector<vector<bool>> used, string subWord, int row, int col) {
        if (used[row][col])
            return false;

        bool sign = false;

        if (board[row][col] != subWord[0])
            return false;
        else {
            used[row][col] = true;

            if (subWord.length() == 1)
                return true;

            if (row < board.size() - 1)
                sign = sign || search(board, used, subWord.substr(1), row + 1, col);

            if (sign)
                return sign;

            if (row > 0)
                sign = sign || search(board, used, subWord.substr(1), row - 1, col);

            if (sign)
                return sign;

            if (col < board[0].size() - 1)
                sign = sign || search(board, used, subWord.substr(1), row, col + 1);

            if (sign)
                return sign;

            if (col > 0)
                sign = sign || search(board, used, subWord.substr(1), row, col - 1);

            if (sign)
                return sign;
        }

        return sign;
    }
};

class Solution {   // 前缀树 回溯
public:
    class TrieNode {
    public:
        string word = "";
        vector<TrieNode*> nodes;
        TrieNode() : nodes(26, NULL) {}
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows == 0 ? 0 : board[0].size();

        if (rows == 0 || cols == 0)
            return res;

        TrieNode* root = new TrieNode();

        for (string word : words) {
            TrieNode* cur = root;

            for (int i = 0; i < word.size(); i++) {
                int idx = word[i] - 'a';

                if (cur->nodes[idx] == NULL)
                    cur->nodes[idx] = new TrieNode();

                cur = cur->nodes[idx];
            }

            cur->word = word;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y) {
        char c = board[x][y];

        if (c == '.' || root->nodes[c - 'a'] == NULL)
            return;

        root = root->nodes[c - 'a'];

        if (root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }

        board[x][y] = '.';

        if (x > 0)
            dfs(board, root, x - 1, y);

        if (y > 0)
            dfs(board, root, x, y - 1);

        if (x + 1 < rows)
            dfs(board, root, x + 1, y);

        if (y + 1 < cols)
            dfs(board, root, x, y + 1);

        board[x][y] = c;
    }

private:
    int rows;
    int cols;
    vector<string> res;
};