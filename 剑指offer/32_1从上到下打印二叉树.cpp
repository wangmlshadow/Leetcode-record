/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
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
// 层次遍历 用队列即可
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            queue<TreeNode*> temp;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                res.push_back(cur->val);

                if (cur->left != nullptr) {
                    temp.push(cur->left);
                }
                if (cur->right != nullptr) {
                    temp.push(cur->right);
                }
            }
            q = temp;
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了71.48%的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了5.46%的用户
*/