#include "normal.h"

/*

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最
近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能
大（一个节点也可以是它自己的祖先）。”
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   // 后序遍历  适用于所有二叉树
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> tra;
        vector<TreeNode*> pS;
        vector<TreeNode*> qS;
        TreeNode* last = NULL;
        TreeNode* point = root;
        int cnt = 0;

        while (point != NULL || !tra.empty()) {
            if (point != NULL) {
                tra.push_back(point);
                point = point->left;
            }
            else {
                point = *tra.rbegin();

                if (point->right != NULL && point->right != last) {
                    point = point->right;
                }
                else {
                    if (point == p) {
                        pS = tra;
                        cnt++;

                        if (cnt == 2)
                            break;
                    }

                    if (point == q) {
                        qS = tra;
                        cnt++;

                        if (cnt == 2)
                            break;
                    }

                    tra.pop_back();
                    last = point;
                    point = NULL;
                }
            }               
        }

        TreeNode* res = root;

        for (int i = 0; i < pS.size() && i < qS.size(); i++) {
            if (pS[i] != qS[i])
                break;

            res = pS[i];
        }

        return res;
    }
};


// 题目给出的二叉搜索树 可以根据值的性质做出解答