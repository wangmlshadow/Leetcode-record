#include "normal.h"

/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {   // 利用层次遍历
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;

        queue<Node*> q;
        Node* end = root;
        q.push(root);

        while (!q.empty()) {
            Node* end_2;

            while (!q.empty()) {
                Node* cur = q.front();
                q.pop();

                if (!q.empty())
                    cur->next = q.front();

                if (cur->left != NULL) {
                    q.push(cur->left);
                    end_2 = cur->left;
                }

                if (cur->right != NULL) {
                    q.push(cur->right);
                    end_2 = cur->right;
                }

                if (cur == end) {
                    cur->next = NULL;
                    end = end_2;
                    break;
                }
            }
        }

        return root;
    }
};

// 利用已经建立的next
class Solution {
public:
    Node* connect(Node* root) {  // 这是完全二叉树
        if (root == NULL)
            return root;

        if (root->left != NULL) {
            root->left->next = root->right;
            
            if (root->next != NULL)
                root->right->next = root->next->left;
            else
                root->right->next = NULL;
        }
            
        connect(root->left);
        connect(root->right);

        return root;
    }
};