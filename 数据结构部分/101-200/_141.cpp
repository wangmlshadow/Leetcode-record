#include "normal.h"

/*
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL)
            return false;

        ListNode* oneStep = head;
        ListNode* twoStep = head;

        while (twoStep != NULL) {
            oneStep = oneStep->next;
            if (twoStep->next != NULL)
                twoStep = twoStep->next->next;
            else
                return false;

            if (oneStep == twoStep)
                return true;
        }

        return false;
    }
};