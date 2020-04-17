#include "normal.h"

/*
给出一个完全二叉树，求出该树的节点个数。
说明：
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数
都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则
该层包含 1~ 2h 个节点。
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {  // 层次遍历
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        TreeNode* end = root;

        while (!q.empty()) {
            TreeNode* cur;

            while (!q.empty()) {
                if (q.front()->left != NULL) {
                    q.push(q.front()->left);
                    cur = q.front()->left;
                }

                if (q.front()->right != NULL) {
                    q.push(q.front()->right);
                    cur = q.front()->right;
                }

                cnt++;

                if (q.front() == end) {
                    end = cur;
                    q.pop();
                    break;
                }

                q.pop();
            }
        }

        return cnt;
    }
};