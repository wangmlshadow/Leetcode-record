#include "normal.h"

/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 层次遍历，不过加上记录每一层遍历的方向
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (root == NULL)
            return res;

        bool sign = true;   // 标记某层遍历时是否为从左到右
        vector<TreeNode*> cur_l;
        cur_l.push_back(root);

        while (!cur_l.empty()) {
            vector<TreeNode*> tmp_t;
            vector<int> tmp_i;

            for (int i = 0; i < cur_l.size(); i++) {
                tmp_i.push_back(cur_l[i]->val);
                
                if (cur_l[i]->left != NULL)
                    tmp_t.push_back(cur_l[i]->left);

                if (cur_l[i]->right != NULL)
                    tmp_t.push_back(cur_l[i]->right);
            }

            if (sign) {
                res.push_back(tmp_i);
                sign = false;
            }
            else {
                reverse(tmp_i.begin(), tmp_i.end());
                res.push_back(tmp_i);
                sign = true;
            }

            cur_l = tmp_t;
        }

        return res;
    }
};  // 执行用时和内存消耗都超过100%