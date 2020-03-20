#include "normal.h"

/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();

        if (len == 0)
            return NULL;

        int pos = 0;

        return create(preorder, pos, inorder, 0, len - 1);
    } 

    TreeNode* create(vector<int>& preorder, int& pos, vector<int>& inorder, int left, int right) {
        if (pos >= preorder.size())
            return NULL;

        TreeNode* root = new TreeNode(preorder[pos]);
        vector<int>::iterator iter = find(inorder.begin(), inorder.end(), preorder[pos]);
        int pos_2 = iter - inorder.begin();

        if (pos_2 <= left)
            root->left = NULL;
        else
            root->left = create(preorder, ++pos, inorder, left, pos_2 - 1);

        if (pos_2 >= right)
            root->right = NULL;
        else
            root->right = create(preorder, ++pos, inorder, pos_2 + 1, right);

        return root;
    }
};