/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = NULL, *fast;
    for (slow = head, fast = head; fast && fast->next; fast = fast->next->next)
        slow = slow->next;
    return slow;
}