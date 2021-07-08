/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 用辅助存储空间 在翻转
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* cur = head;
        while (cur != NULL) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }  
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了41.88%的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了54.05%的用户
*/

// 可以用递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        rTraverse(head, res);
        return res;
    }

    void rTraverse(ListNode* cur, vector<int>& res) {
        if (cur == NULL) {
            return;
        }
        rTraverse(cur->next, res);
        res.push_back(cur->val);
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：8.8 MB, 在所有 C++ 提交中击败了22.54%的用户
*/
