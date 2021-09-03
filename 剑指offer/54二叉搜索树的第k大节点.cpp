/*
给定一棵二叉搜索树，请找出其中第k大的节点。
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
    int kthLargest(TreeNode* root, int k) {
        k_ = k;
        res = 0;
        cnt = 1;
        tra(root);
        return res;
    }

    void tra(TreeNode* root) {
        if (root == nullptr || cnt > k_) return;

        tra(root->right);

        if (cnt == k_) {
            res = root->val;
            ++cnt;
            return;
        }

        ++cnt;

        tra(root->left);
    }

private:
    int res;
    int cnt;
    int k_;
};
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 C++ 提交中击败了94.34%的用户
内存消耗：23.5 MB, 在所有 C++ 提交中击败了55.03%的用户
通过测试用例：91 / 91
*/