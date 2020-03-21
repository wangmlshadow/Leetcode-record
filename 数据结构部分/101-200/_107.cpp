#include "normal.h"

/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // 转置层次遍历的结果
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        TreeNode* end = root;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            TreeNode* end_2 = NULL;

            while (!q.empty()) {
                TreeNode* cur = q.front();
                temp.push_back(cur->val);
                q.pop();

                if (cur->left != NULL) {
                    q.push(cur->left);
                    end_2 = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    end_2 = cur->right;
                }
                    
                if (end == cur) {
                    end = end_2;
                    break;
                }                    
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};