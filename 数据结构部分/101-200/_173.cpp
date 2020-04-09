#include "normal.h"

/*
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        fillVal(root);
        sort(val.begin(), val.end());
        pos = 0;
    }

    /** @return the next smallest number */
    int next() {
        pos++;
        return val[pos - 1];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return pos < val.size();
    }

    void fillVal(TreeNode* root) {
        if (root == NULL)
            return;

        val.push_back(root->val);
        fillVal(root->left);
        fillVal(root->right);
    }

private:
    vector<int> val;
    int pos;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */