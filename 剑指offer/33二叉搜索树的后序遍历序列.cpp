/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

// 递归判断 左子树小于根节点 右子树大于根节点
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return isTrue(postorder, 0, postorder.size() - 1);
    }

    bool isTrue(vector<int>& postorder, int left, int right) {
        if (left >= right) {
            return true;
        }

        // 找出右子树部分child_r->right - 1
        int child_r = right - 1;
        while (child_r >= left && postorder[right] < postorder[child_r]) {
            --child_r;
        }
        // 左子树 left->child_r
        // 左子树所有结点小于根节点
        for (int i = left; i < child_r; ++i) {
            if (postorder[right] <= postorder[i]) {
                return false;
            }
        }

        return isTrue(postorder, left, child_r) && isTrue(postorder, child_r + 1, right - 1);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了17.64%的用户
*/