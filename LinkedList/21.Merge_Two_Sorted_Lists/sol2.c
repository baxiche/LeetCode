/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode **cur = &head;
    struct ListNode **node = NULL;
    
    while (l1 && l2){
        node = (l1->val < l2->val)? &l1 : &l2;
        *cur = *node;
        *node = (*node)->next;
        cur = &((*cur)->next);
    }
    if (l1) *cur = l1;
    if (l2) *cur = l2;
    
    return head;
}