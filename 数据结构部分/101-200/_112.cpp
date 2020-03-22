#include "normal.h"

/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        return solution(root, sum);
    }

    bool solution(TreeNode* root, int sum) {
        if (root->left == NULL && root->right == NULL)
            return root->val == sum;

        bool sign_1 = false, sign_2 = false;

        if (root->left != NULL)
            sign_1 = solution(root->left, sum - root->val);

        if (root->right != NULL)
            sign_2 = solution(root->right, sum - root->val);

        return sign_1 || sign_2;
    }
};