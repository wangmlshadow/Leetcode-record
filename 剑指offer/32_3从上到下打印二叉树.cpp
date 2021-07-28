/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool rev = false; // 之字形 记录是否需要反转

        while (!q.empty()) {
            queue<TreeNode*> temp;
            vector<int> tempRes;

            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                tempRes.push_back(cur->val);

                if (cur->left != nullptr) {
                    temp.push(cur->left);
                }
                if (cur->right != nullptr) {
                    temp.push(cur->right);
                }
            }
            if (rev) {
                reverse(tempRes.begin(), tempRes.end());
            }
            rev = !rev;
            res.push_back(tempRes);
            q = temp;
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了80.84%的用户
内存消耗：13.2 MB, 在所有 C++ 提交中击败了5.00%的用户
*/