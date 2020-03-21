#include "normal.h"

/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;

        int left = 0, right = 0;

        return solution(root, left, right) && abs(left - right) <= 1;
    }

    bool solution(TreeNode* root, int& left, int& right) {  // 判断左右子树是否为平衡二叉树，并返回左右子树的高
        if (root == NULL) {
            left = 0;
            right = 0;
            return true;
        }

        int left_1 = 0, left_2 = 0;
        int right_1 = 0, right_2 = 0;

        bool sign_l = solution(root->left, left_1, right_1);
        bool sign_r = solution(root->right, left_2, right_2);

        left = 1 + max(left_1, right_1);
        right = 1 + max(left_2, right_2);

        return sign_l && sign_r && abs(left - right) <= 1;
    }
};