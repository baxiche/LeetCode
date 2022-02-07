/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, **cur = &head, **node = NULL;
    
    while (l1 && l2){
        node = (l1->val < l2->val)? &l1 : &l2;
        *cur = *node;
        *node = (*node)->next;
        cur = &((*cur)->next);
    }
    
    *cur = (l1)? l1 : l2;
    return head;
}