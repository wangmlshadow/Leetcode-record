#include "normal.h"

/*
给定一个二叉树，返回它的 前序 遍历。
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // 非递归
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        stack<TreeNode*> helper;
        TreeNode* p = NULL;
        helper.push(root);

        while (!helper.empty()) {
            p = helper.top();
            res.push_back(p->val);
            helper.pop();

            if (p->right != NULL)
                helper.push(p->right);

            if (p->left != NULL)
                helper.push(p->left);
        }

        return res;
    }
};