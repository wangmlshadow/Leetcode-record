/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 使用vector存储每一条路径 然后比较路径和是否符合条件 下面代码是这种方式
// 为了节省空间以及复制vector的时间 可以采用类似回溯的方式 仅使用一个vector，此版本在go语言的答案中进行了实现，运行结果显示，也确实比上一个方法花费的时间空间都要少得多
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        addPath(res, {}, root, target);
        return res;
    }

    void addPath(vector<vector<int>>& res, vector<int> path, TreeNode* root, int target) {
        if (root->val == target && (root->left == nullptr && root->right == nullptr)) {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }

        path.push_back(root->val);
        target -= root->val;

        if (root->left != nullptr) {
            addPath(res, path, root->left, target);
        }
        if (root->right != nullptr) {
            addPath(res, path, root->right, target);
        }
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 C++ 提交中击败了19.78%的用户
内存消耗：32.9 MB, 在所有 C++ 提交中击败了16.11%的用户
*/