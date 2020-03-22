#include "normal.h"

/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {  // 利用层次遍历的方式
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int cnt = 1;
        queue<TreeNode*> q;
        TreeNode* end = root;
        q.push(root);

        while (!q.empty()) {
            TreeNode* end_2 = NULL;

            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left == NULL && cur->right == NULL)
                    return cnt;

                if (cur->left != NULL) {
                    q.push(cur->left);
                    end_2 = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    end_2 = cur->right;
                }

                if (cur == end) {
                    end = end_2;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

// 还可以用递归试试