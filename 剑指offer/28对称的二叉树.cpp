/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
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

// 根节点的左子树和根节点的右子树的镜像一模一样 则对称
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        // 创建右子树镜像
        trav(root->right);
        return equ(root->left, root->right);
    }

    // 镜像
    void trav(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        swap(root->left, root->right);
        trav(root->left);
        trav(root->right);
    }
    // 判断两棵树是否一致
    bool equ(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if ((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return equ(left->left, right->left) && equ(left->right, right->right);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：15.9 MB, 在所有 C++ 提交中击败了53.21%的用户
*/

// 将镜像翻转合并到equ这一步
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }    
        return equ(root->left, root->right);
    }

    // 判断两棵树是否互为镜像
    bool equ(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return equ(left->left, right->right) && equ(left->right, right->left);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了48.74%的用户
内存消耗：15.7 MB, 在所有 C++ 提交中击败了94.30%的用户
*/