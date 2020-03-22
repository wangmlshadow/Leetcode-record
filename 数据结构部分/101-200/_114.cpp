#include "normal.h"

/*
给定一个二叉树，原地将它展开为链表。
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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode* temp = NULL;
        TreeNode** cur = &temp;
        *cur = root;

        solution(root, cur);
    }

    void solution(TreeNode* root, TreeNode** cur) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;

        if (left != NULL) {
            *cur = left;
            root->right = left;
            solution(left, cur);
            
        }

        if (right != NULL) {
            (*cur)->right = right;
            *cur = right;
            solution(right, cur);
        }
    }
};