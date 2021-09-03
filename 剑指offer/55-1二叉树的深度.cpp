/*
输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
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
// 可以用层次遍历，但是这里用递归，因为简单
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return tra(root);
    }

    int tra(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(tra(root->left), tra(root->right));
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了96.38%的用户
内存消耗：18.4 MB, 在所有 C++ 提交中击败了52.79%的用户
通过测试用例：39 / 39
*/