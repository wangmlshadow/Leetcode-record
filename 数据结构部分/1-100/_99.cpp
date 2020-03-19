#include "normal.h"

/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> vec;
        TreeNode* p = root;

        while (p != NULL || !st.empty()) {    // 获取中序遍历序列
            if (p != NULL) {
                st.push(p);
                p = p->left;
            }
            else {
                vec.push_back(st.top());
                p = st.top()->right;
                st.pop();
            }               
        }

        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i]->val > vec[i + 1]->val) {    // 寻找需要交换的两个点，中序序列应该有序，从无序开始处开始寻找
                int j = i + 1;

                while (j + 1 < vec.size() && vec[i]->val > vec[j + 1]->val)
                    j++;

                int val = vec[i]->val;
                vec[i]->val = vec[j]->val;
                vec[j]->val = val;
                break;
            }
        }
    }
};