
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    int size;
    Node *head;
} MyLinkedList;

typedef MyLinkedList List;

MyLinkedList* myLinkedListCreate() {
    List *tmp = (List *)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->size = 0;
    return tmp;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index + 1 > obj->size) return -1;

    Node *cur = obj->head;
    for (int i = 0; i < index; ++i) cur = cur->next;
    return cur->data;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, obj->size, val);
    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->size) return;

    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = val;

    Node **cur = &(obj->head);
    for (int i = 0; i < index; ++i) cur = &((*cur)->next);
    tmp->next = *cur;
    *cur = tmp;
    ++obj->size;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index + 1 > obj->size) return;

    Node **cur = &(obj->head);
    for (int i = 0; i < index; ++i) cur = &((*cur)->next);
    *cur = (*cur)->next;
    --obj->size;
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/