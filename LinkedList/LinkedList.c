#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node *head;
} List;

List *creat(){
    List *tmp = (List *)malloc(sizeof(List));
    tmp->head = NULL; 
    tmp->size = 0;
    return tmp;
}

int get(List *obj, int index){
    if (index + 1 > obj->size) return -1;

    Node *cur = obj->head;
    for (int i = 0; i < index; ++i) cur = cur->next;
    return cur->data;
}

void insertHead(List *obj, int val){
    insertAt(obj, 0, val);
    return;
}

void insertTail(List *obj, int val){
    insertAt(obj, obj->size, val);
    return;
}

void insertAt(List *obj, int index, int val){
    if (index > obj->size) return;

    ++obj->size;
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = val;

    Node **cur = &(obj->head);
    for (int i = 0; i < index; ++i) cur = &((*cur)->next);
    tmp->next = *cur;
    *cur = tmp;
    return;
}

void removeAt(List *obj, int index){
    if (index + 1 > obj->size) return;

    --obj->size;
    Node **cur = &(obj->head);
    for (int i = 0; i < index; ++i) cur = &((*cur)->next);
    *cur = (*cur)->next;
    return;
}

void freeList(List *obj){
    Node *cur = obj->head;
    while (cur){
        cur = obj->head->next;
        free(obj->head);
        obj->head = cur;
    }
    free(obj);
    return;
}