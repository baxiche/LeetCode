#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    int size;
    struct ListNode *nodes[10127];
} heap;

heap *heap_init(){
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    h->nodes[0] = NULL;
    return h;
}

void heap_push(heap *h, struct ListNode *head){
    if (!head) return;
    
    int i = ++h->size;
    while (i != 1){
        if ((h->nodes[i / 2])->val < head->val) break;
        else {
            h->nodes[i] = h->nodes[i / 2];
            i /= 2;
        }
    }
    h->nodes[i] = head;
    return;
}

struct ListNode *heap_pop(heap *h){
    struct ListNode *m = h->nodes[1];
    struct ListNode *last = h->nodes[h->size--];

    int i, child;
    for (i = 1; i * 2 <= h->size; i = child){
        child = i * 2;
        if (child < h->size && (h->nodes[child])->val > (h->nodes[child + 1]->val)) ++child;

        if (last->val <= (h->nodes[child])->val) break;
        else h->nodes[i] = h->nodes[child];
    }
    h->nodes[i] = last;
    return m;
}

bool heap_empty(heap *h) {return h->size == 0;}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0) return NULL;

    heap *h = heap_init();
    for (int i = 0; i < listsSize; ++i) heap_push(h, lists[i]);

    struct ListNode *head = NULL;
    struct ListNode **cur = &head;
    while (!heap_empty(h)){
        *cur = heap_pop(h);
        if ((*cur)->next) heap_push(h, (*cur)->next);
        cur = &((*cur)->next);
    }

    return head;
}