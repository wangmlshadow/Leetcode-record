#include "normal.h"

/*

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

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
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return root->val;

        int sum = 0;

        if (root->left != NULL)
            solution(root->left, root->val, sum);

        if (root->right != NULL)
            solution(root->right, root->val, sum);

        return sum;
    }

    void solution(TreeNode* root, int ahead, int& sum) {
        if (root->left == NULL && root->right == NULL) {
            sum += (10 * ahead + root->val);
            return;
        }

        if (root->left != NULL)
            solution(root->left, ahead * 10 + root->val, sum);

        if (root->right != NULL)
            solution(root->right, ahead * 10 + root->val, sum);
    }
};