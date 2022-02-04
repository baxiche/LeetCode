/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head;
    struct ListNode **cur = &head;
    for (; l1 && l2; cur = &((*cur)->next)){
        if (l1->val < l2->val){
            *cur = l1;
            l1 = l1->next;
        }
        else {
            *cur = l2;
            l2 = l2->next;
        }
    }
    if (l1) *cur = l1;
    if (l2) *cur = l2;

    return head;
}