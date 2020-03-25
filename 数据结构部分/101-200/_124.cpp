#include "normal.h"

/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
*/


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max = root->val;

        transMax(root, max);

        return max;
    }

    int transMax(TreeNode* root, int& max) {   // 记录经过这个节点所有路径中最长的一条
        if (root == NULL)
            return 0;

        int left = transMax(root->left, max);
        int right = transMax(root->right, max);

        int val = root->val;

        if (left > 0)
            val += left;

        if (right > 0)
            val += right;

        if (max < val)
            max = val;

        if (left > right && left > 0) 
            root->val += left;

        if (right > left && right > 0)
            root->val += right;

        return root->val;
    }
};