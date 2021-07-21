/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        trav(root);
        return root;
    }

    void trav(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        swap(root->left, root->right);
        trav(root->left);
        trav(root->right);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了50.84%的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了76.43%的用户
*/