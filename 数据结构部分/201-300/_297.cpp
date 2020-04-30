#include "normal.h"

/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个
文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非
必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Codec {    // 有问题 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "null";

        string res = to_string(root->val);
        NLR(root->left, res);
        NLR(root->right, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[0] == 'n')
            return NULL;

        int len = data.length();
        int pos = 0;
        return createTree(data, pos, len);
    }

    void NLR(TreeNode* root, string& res) {
        if (root == NULL) {
            res += ",null,";
            return;
        }

        res += "," + to_string(root->val);
        NLR(root->left, res);
        NLR(root->right, res);
    }

    TreeNode* createTree(string& data, int& pos, int len) {
        if (pos >= len)
            return NULL;

        if (data[pos] == 'n') {
            pos += 5;
            return NULL;
        }

        int begin = pos;

        while (pos + 1 < len && data[pos + 1] != ',') {
            pos++;
        }

        string str = data.substr(begin, pos - begin + 1);
        int num = atoi(str.c_str());
        TreeNode* root = new TreeNode(num);
        root->left = createTree(data, pos, len);
        root->right = createTree(data, pos, len);
        return root;
    }
};


class Codec {   // 超时 
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return rserialize(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> strs;
        int len = data.length();

        for (int i = 0; i < len; i++) {
            string str;
            while (i < len && data[i] != ',') {
                str.push_back(data[i++]);
            }
            strs.push(str);
        }

        return rdeserialize(strs);
    }

    string rserialize(TreeNode* root, string str) {
        if (root == NULL)
            str += "null,";
        else {
            str += to_string(root->val) + ",";
            str = rserialize(root->left, str);
            str = rserialize(root->right, str);
        }

        return str;
    }

    TreeNode* rdeserialize(queue<string>& strs) {
        if (!strs.empty() && strs.front() == "null") {
            strs.pop();
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(strs.front()));
        strs.pop();
        root->left = rdeserialize(strs);
        root->right = rdeserialize(strs);

        return root;
    }
};


class Codec {    // 最长的测试案例 还是超时
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return rserialize(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> strs;
        int len = data.length();

        for (int i = 0; i < len; i++) {
            string str;
            while (i < len && data[i] != ',') {
                str.push_back(data[i++]);
            }
            strs.push_back(str);
        }
        
        int pos = 0;
        return rdeserialize(strs, pos);
    }

    string rserialize(TreeNode* root, string str) {
        if (root == NULL)
            str += "null,";
        else {
            str += to_string(root->val) + ",";
            str = rserialize(root->left, str);
            str = rserialize(root->right, str);
        }

        return str;
    }

    TreeNode* rdeserialize(vector<string>& strs, int& pos) {
        if (pos < strs.size() && strs[pos] == "null") {
            pos++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(strs[pos]));
        pos++;
        root->left = rdeserialize(strs, pos);
        root->right = rdeserialize(strs, pos);

        return root;
    }
};



class Codec {   // BFS
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;

        while (!q.empty()) {
            TreeNode* p = q.front();
            q.pop();

            if (p != NULL) {
                res += to_string(p->val) + ",";
                q.push(p->left);
                q.push(p->right);
            }
            else {
                res += "null,";
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        split(data, vals);
        queue<TreeNode*> q;
        
        if (vals[0] == "null")
            return NULL;

        q.push(new TreeNode(stoi(vals[0])));
        TreeNode* res = q.front();

        for (int i = 1; i < vals.size(); ) {
            if (vals[i] != "null") {
                TreeNode* p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->left = p;
            }

            ++i;

            if (vals[i] != "null") {
                TreeNode* p = new TreeNode(stoi(vals[i]));
                q.push(p);
                q.front()->right = p;
            }

            ++i;
            q.pop();
        }

        return res;
    }

    void split(string& data, vector<string>& res) {
        int start = 0;
        int len = data.length();

        while (true) {
            int end = data.find(',', start);
            
            if (end == string::npos)
                break;

            res.push_back(data.substr(start, end - start));
            start = end + 1;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));