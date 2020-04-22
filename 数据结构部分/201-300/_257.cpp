#include "normal.h"

/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if (root == NULL)
            return res;

        string head = to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            res.push_back(head);
            return res;
        }

        if (root->left != NULL)
            addPath(root->left, head, res);

        if (root->right != NULL)
            addPath(root->right, head, res);

        return res;
    }

    void addPath(TreeNode* p, string path, vector<string>& res) {
        path = path + "->" + to_string(p->val);

        if (p->left == NULL && p->right == NULL) {
            res.push_back(path);
            return;
        }

        if (p->left != NULL)
            addPath(p->left, path, res);

        if (p->right != NULL)
            addPath(p->right, path, res);
    }
};