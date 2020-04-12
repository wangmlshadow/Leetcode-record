#include "normal.h"

/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
    vector<int> rightSideView(TreeNode* root) {   // 层次遍历
        vector<int> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> helper;
        helper.push(root);
        TreeNode* last = root;

        while (!helper.empty()) {
            TreeNode* cur;
            
            while (!helper.empty()) {
                if (helper.front()->left != NULL) {
                    helper.push(helper.front()->left);
                    cur = helper.front()->left;
                }

                if (helper.front()->right != NULL) {
                    helper.push(helper.front()->right);
                    cur = helper.front()->right;
                }

                if (last == helper.front()) {
                    res.push_back(helper.front()->val);
                    last = cur;
                }

                helper.pop();
            }            
        }

        return res;
    }
};