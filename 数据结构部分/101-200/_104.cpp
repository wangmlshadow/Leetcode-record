#include "normal.h"

/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 可以用层次遍历的方法，但也可以用递归做，下面用的时递归的方法
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = 0, right = 0;

        if (root->left != NULL)
            left = maxDepth(root->left);

        if (root->right != NULL)
            right = maxDepth(root->right);

        return 1 + max(left, right);
    }
};   // 递归不需要额外的存储空间，但是比较慢