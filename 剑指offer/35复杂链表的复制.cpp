/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* res = NULL;
        if (head == NULL) {
            return res;
        }
        
        // 通过两个map 得到新旧节点之间的映射关系 从而在连接random时使用
        map<Node*, int> rowMap;
        map<int, Node*> resMap;
        int cnt = 0;
        
        res = new Node(head->val);
        rowMap[head] = cnt;
        resMap[cnt] = res;
        cnt++;

        Node* curRow = head->next;
        Node* curRes = res;

        // new 新链表
        while (curRow != NULL) {
            Node* temp = new Node(curRow->val);
            curRes->next = temp;
            curRes = temp;
            rowMap[curRow] = cnt;
            resMap[cnt] = temp;
            curRow = curRow->next;
            cnt++;
        }

        // 连接 random
        curRes = res;
        curRow = head;
        while (curRow != NULL) {
            if (curRow->random != NULL) {
                int index = rowMap[curRow->random];
                curRes->random = resMap[index];
            }
            curRow = curRow->next;
            curRes = curRes->next;
        }
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了87.23%的用户
内存消耗：11.5 MB, 在所有 C++ 提交中击败了5.07%的用户
*/