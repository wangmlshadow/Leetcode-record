#include "normal.h"

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示
为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的
祖先）。”

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
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