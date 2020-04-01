#include "normal.h"

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {    // 使用set
public:
    ListNode* detectCycle(ListNode* head) {
        set<ListNode*> helper;

        if (head == NULL)
            return NULL;

        ListNode* cur = head->next;
        helper.insert(head);

        while (cur != NULL) {
            if (helper.find(cur) != helper.end())
                return cur;

            helper.insert(cur);
            cur = cur->next;
        }

        return NULL;
    }
};


// 还可以使用双指针