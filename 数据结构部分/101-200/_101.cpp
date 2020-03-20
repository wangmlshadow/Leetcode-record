#include "normal.h"

/*
给定一个二叉树，检查它是否是镜像对称的。
*/


//Definition for a binary tree node.
struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return solution(root->left, root->right);
    }

    bool solution(TreeNode* left, TreeNode* right) {
        if (left == NULL)
            return right == NULL;

        if (right == NULL)
            return left == NULL;

        if (left->val != right->val)
            return false;

        return solution(left->left, right->right) && solution(left->right, right->left);
    }
};