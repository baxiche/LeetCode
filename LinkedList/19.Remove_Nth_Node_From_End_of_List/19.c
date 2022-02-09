/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast = head;
    for (int i = 0; i < n; ++i) fast = fast->next;

    struct ListNode **cur = &head;
    for (; fast; fast = fast->next) cur = &((*cur)->next);
    
    *cur = (*cur)->next;
    return head;
}