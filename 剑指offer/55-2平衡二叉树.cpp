/*输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。*/

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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        tra(root, result);
        return result;
    }

    int tra(TreeNode *root, bool& result) {
        if (!result) return 0;

        if (root == nullptr) return 0;

        int left = tra(root->left, result);
        int right = tra(root->right, result);

        if (abs(right - left) > 1) {
            result = false;
        } 

        return 1 + max(left, right);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：16 ms, 在所有 C++ 提交中击败了44.45%的用户
内存消耗：20.4 MB, 在所有 C++ 提交中击败了36.80%的用户
通过测试用例：227 / 227
*/