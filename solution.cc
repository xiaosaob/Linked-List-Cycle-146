// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

// Follow up:
// Can you solve it without using extra space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        while(second) {
            second = second->next;
            if(second)
                second = second->next;
            first = first->next;
            if(first && first == second)
                break;
        }
        if(!second) return NULL;
        first = head;
        while(first != second) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};
