/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 递归反转链表
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* res = reverse(head);
        head->next = NULL;
        return res;
    }

    ListNode* reverse(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }
        ListNode* res = reverse(head->next);
        head->next->next = head;
        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：4 ms, 在所有 C++ 提交中击败了95.84%的用户
内存消耗：8.3 MB, 在所有 C++ 提交中击败了5.23%的用户
*/