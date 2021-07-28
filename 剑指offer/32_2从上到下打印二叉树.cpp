/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
            res.push_back(tempRes);
            q = temp;
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了33.27%的用户
内存消耗：13.1 MB, 在所有 C++ 提交中击败了5.03%的用户
*/