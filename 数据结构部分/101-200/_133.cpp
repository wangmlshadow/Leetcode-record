#include "normal.h"

/*
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
*/


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        map<int, Node*> sign; // 判断某个节点是否已经
        return addNode(node, sign);
    }

    Node* addNode(Node* parent, map<int, Node*>& sign) {
        map<int, Node*>::iterator key = sign.find(parent->val);

        if (key != sign.end())
            return sign[parent->val];

        int val = parent->val;
        Node* cur = new Node(val);
        sign[val] = cur;

        for (auto i : parent->neighbors) {
            cur->neighbors.push_back(addNode(i, sign));
        }

        return cur;
    }
};