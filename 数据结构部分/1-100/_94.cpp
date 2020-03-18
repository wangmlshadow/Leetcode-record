#include "normal.h"

/*
给定一个二叉树，返回它的中序 遍历。
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 不用递归
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mySt;
        TreeNode* p = root;

        while (p != NULL || !mySt.empty()) {
            if (p != NULL) {
                mySt.push(p);
                p = p->left;
            }
            else {
                TreeNode* top = mySt.top();
                mySt.pop();
                result.push_back(top->val);
                p = top->right;
            }
        }

        return result;
    }
};