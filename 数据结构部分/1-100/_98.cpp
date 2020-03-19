#include "normal.h"

/*

给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {       
        return solution(root, NULL, NULL);
    }

    bool solution(TreeNode* root, TreeNode* min, TreeNode* max) {     // 保存上下界
        if (root == NULL)
            return true;

        if (min != NULL && root->val <= min->val)
            return false;

        if (max != NULL && root->val >= max->val)
            return false;

        return solution(root->left, min, root) && solution(root->right, root, max);
    }
};