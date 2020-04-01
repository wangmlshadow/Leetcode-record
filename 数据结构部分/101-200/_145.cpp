#include "normal.h"

/*
给定一个二叉树，返回它的 后序 遍历。
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        TreeNode* p = root;
        TreeNode* last = NULL;
        stack<TreeNode*> helper;

        while (p != NULL || !helper.empty()) {
            if (p != NULL) {
                helper.push(p);
                p = p->left;
            }
            else {
                p = helper.top();

                if (p->right != NULL && p->right != last) {
                    helper.push(p->right);
                    p = p->right->left;
                }
                else {
                    helper.pop();
                    res.push_back(p->val);
                    last = p;
                    p = NULL;
                }
            }
        }

        return res;
    }
};