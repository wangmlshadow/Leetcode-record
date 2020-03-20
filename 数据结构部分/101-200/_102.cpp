#include "normal.h"

/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 使用队列作为辅助进行层次遍历
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        TreeNode* end = root;   // 记录每一层的最后一个节点，用于确定是否遍历完一层

        while (!q.empty()) {
            vector<int> temp;
            TreeNode* last;
            TreeNode* cur;
            while (!q.empty()) {
                cur = q.front();
                temp.push_back(cur->val);
                
                if (cur->left != NULL) {
                    q.push(cur->left);
                    last = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    last = cur->right;
                }

                q.pop();

                if (cur == end) {
                    end = last;
                    break;
                }
            }

            res.push_back(temp);
        }

        return res;
    }
};