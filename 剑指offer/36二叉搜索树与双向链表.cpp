/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。

特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

// 最简单的 使用辅助存储空间 保存二叉搜索树中序遍历的序列 在逐个调整每个节点左右指针指向
// 空间换时间 执行结果显示 执行速度确实是最快的
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL) {
            root->left = root;
            root->right = root;
            return root;
        }

        vector<Node*> nodeArray;
        tra(root, nodeArray);

        for (int i = 0; i < nodeArray.size(); ++i) {
            if (i == 0) {
                nodeArray[i]->left = nodeArray[nodeArray.size() - 1];
                nodeArray[i]->right = nodeArray[i + 1];
            }
            else if (i == nodeArray.size() - 1) {
                nodeArray[i]->left = nodeArray[i - 1];
                nodeArray[i]->right = nodeArray[0];
            }
            else {
                nodeArray[i]->left = nodeArray[i - 1];
                nodeArray[i]->right = nodeArray[i + 1];
            }
        }

        return nodeArray[0];
    }

    void tra(Node* root, vector<Node*>& nodeArray) {
        if (root == NULL) {
            return;
        }

        tra(root->left, nodeArray);
        nodeArray.push_back(root);
        tra(root->right, nodeArray);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了5.00%的用户
*/

// 直接在中序遍历的过程中修改 不使用辅助数组
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL) {
            root->left = root;
            root->right = root;
            return root;
        }

        Node* res = NULL;
        Node* pre = NULL;

        tra(root, &pre, &res);

        res->left = pre;
        pre->right = res;

        return res;
    }

    void tra(Node* root, Node** ppre, Node** pres) {
        if (root == NULL) {
            return;
        }

        tra(root->left, ppre, pres);

        if (*pres == NULL) {
            *pres = root;
        }
        
        if (*ppre != NULL) {
            (*ppre)->right = root;
        }
        root->left = *ppre;
        *ppre = root;

        tra(root->right, ppre, pres);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了45.49%的用户
内存消耗：7.4 MB, 在所有 C++ 提交中击败了50.35%的用户
*/

// 直接在中序遍历的过程中修改 不使用辅助数组 不使用递归的遍历方式
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        if (root->left == NULL && root->right == NULL) {
            root->left = root;
            root->right = root;
            return root;
        }

        Node* pre = NULL;
        stack<Node*> sta;
        Node* p = root;
        Node* res = NULL;
        bool isRes = true;

        while (p != NULL || !sta.empty()) {
            if (p != NULL) {
                sta.push(p);
                p = p->left;
            }
            else {
                p = sta.top();
                if (isRes) { // 只执行一次
                    res = p;
                    isRes = false;
                }
                
                if (pre != NULL) {
                    pre->right = p;
                }

                p->left = pre;
                sta.pop();
                pre = p;
                p = p->right;
            }
        }

        // pre最终的指向二叉树最右节点 即值最大的节点 也是链表中最后一个节点
        pre->right = res;
        res->left = pre;

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了92.59%的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了16.53%的用户
*/