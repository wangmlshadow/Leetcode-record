#include "normal.h"

/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
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

class Solution {
public:
    Node* connect(Node* root) {  // 不是完全二叉树 只能用层次遍历
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