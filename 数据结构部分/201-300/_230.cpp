#include "normal.h"

/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int cnt = 0;
        TreeNode* p = root;

        while (p != NULL || !s.empty()) {
            if (p != NULL) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top();
                cnt++;

                if (cnt == k)
                    return p->val;

                s.pop();
                p = p->right;
            }
        }

        return 0;
    }
};