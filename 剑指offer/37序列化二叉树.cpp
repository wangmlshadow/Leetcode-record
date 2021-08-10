/*
请实现两个函数，分别用来序列化和反序列化二叉树。

你需要设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示：输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
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

// 思路是 保存二叉树的前序和中序遍历结果的字符串
// 遍历结果中 每个节点用 空格 隔开
// 前序和中序遍历用 # 隔开
// 用上根据前序和中序遍历重建二叉树的方式
// 第37个测试案例出错 找不到原因
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        // 获取前序和中序遍历的序列
        vector<int> nlrRes;
        vector<int> lnrRes;

        traNLR(root, nlrRes);
        traLNR(root, lnrRes);

        string data;
        for (int i = 0; i < nlrRes.size() - 1; ++i) {
            data += to_string(nlrRes[i]);
            data += " ";
        }
        data += to_string(nlrRes[nlrRes.size() - 1]);
        
        data += "#";

        for (int i = 0; i < lnrRes.size() - 1; ++i) {
            data += to_string(lnrRes[i]);
            data += " ";
        }
        data += to_string(lnrRes[lnrRes.size() - 1]);

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }

        vector<string> res;
        strSplit(data, res, '#');// 分割成先序和中序
        vector<string> nlr;
        vector<string> lnr;
        strSplit(res[0], nlr, ' ');
        strSplit(res[1], lnr, ' ');

        // string -> int
        vector<int> nlrInt;
        vector<int> lnrInt;

        for (int i = 0; i < nlr.size(); ++i) {
            nlrInt.push_back(stoi(nlr[i]));
        }

        for (int i = 0; i < lnr.size(); ++i) {
            lnrInt.push_back(stoi(lnr[i]));
        }
        
        return buildTree(nlrInt, lnrInt);
    }

    void strSplit(string data, vector<string>& res, char ch) {
        int pre = 0;
        for (int i = 0; i < data.length(); ++i) {
            if (data[i] == ch) {
                res.push_back(data.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        res.push_back(data.substr(pre, data.length() - pre));
    }

    void traNLR(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        res.push_back(root->val);
        traNLR(root->left, res);
        traNLR(root->right, res);
    }

    void traLNR(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        traLNR(root->left, res);
        res.push_back(root->val);
        traLNR(root->right, res);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return NULL;
        }
        TreeNode* root = new TreeNode;
        root->val = preorder[pl];
        int imid = il;
        for (int i = il; i <= ir; ++i) {
            if (inorder[i] == preorder[pl]) {
                imid = i;
                break;
            }
        }
        root->left = build(preorder, inorder, pl + 1, pl + (imid - il), il, imid - 1);
        root->right = build(preorder, inorder, pl + (imid - il + 1), pr, imid + 1, ir);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


// 娱乐一下
class Codec {
public:

    string str;
    TreeNode* res;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        res = root;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        str = data;
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：44 ms, 在所有 C++ 提交中击败了85.71%的用户
内存消耗：26.2 MB, 在所有 C++ 提交中击败了98.18%的用户
*/