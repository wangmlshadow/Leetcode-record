/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
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

// 已知先序 中序 根据二叉树先序中序的性质 即可获取完整二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return NULL;
        }
        TreeNode* root = new TreeNode;
        root->val = preorder[pl];
        int imid = il;
        for (int i = il; i <= ir; ++i) {
            if (inorder[i] == preorder[pl]) {
                imid = i;
                break;
            }
        }
        root->left = build(preorder, inorder, pl + 1, pl + (imid - il), il, imid - 1);
        root->right = build(preorder, inorder, pl + (imid - il + 1), pr, imid + 1, ir);
        return root;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：40 ms, 在所有 C++ 提交中击败了32.80%的用户
内存消耗：24.5 MB, 在所有 C++ 提交中击败了73.60%的用户
*/