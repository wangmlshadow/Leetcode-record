/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。
*/

// 递归遍历
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL || B == NULL) {
            return false;
        }
        res = false;
        trav(A, B);
        return res;
    }

    // 从A B作为根节点的两棵树是否A可以包含B
    bool isSub(TreeNode* A, TreeNode* B) {
        if (B == NULL) {
            return true;
        }
        if (A == NULL && B != NULL) {
            return false;
        }
        if (A->val != B->val) {
            return false;
        }
        return isSub(A->left, B->left) && isSub(A->right, B->right); 
    }

    // 先序遍历 并按个节点测试
    void trav(TreeNode* A, TreeNode* B) {
        if (A == NULL || res) {
            return;
        }
        if (isSub(A, B)) {
            res = true;
        }
        trav(A->left, B);
        trav(A->right, B);
    }
private:
    bool res;
};
/*
执行结果：通过 显示详情 添加备注
执行用时：44 ms, 在所有 C++ 提交中击败了82.56%的用户
内存消耗：32.9 MB, 在所有 C++ 提交中击败了35.16%的用户
*/