#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int data[100];
} heap;

heap *heap_init();
void heap_push(heap *h, int val);
int heap_pop(heap *h);
bool heap_empty(heap *h);

int main(){
    int a[5];
    for (int i = 0; i < 5; ++i) scanf("%d", a + i);

    heap *pq = heap_init();
    for (int i = 0; i < 5; ++i) heap_push(pq, a[i]);
    while (!heap_empty(pq)){
        int tmp = heap_pop(pq);
        printf("%d ", tmp);
    }
}

heap *heap_init(){
    heap *h = (heap *)malloc(sizeof(heap));
    h->size = 0;
    return h;
}

void heap_push(heap *h, int val){
    int i = ++h->size;
    while (i > 1){
        if (h->data[i / 2] > val){
            h->data[i] = h->data[i / 2];
            i /= 1;
        }
        else break;
    }
    h->data[i] = val;
    return;
}

int heap_pop(heap *h){
    int m = h->data[1];
    int last = h->data[h->size--];

    int i, child;
    for (i = 1; i * 2 <= h->size; i = child){
        child = i * 2;
        if (child < h->size && h->data[child] > h->data[child + 1]) ++child;

        if (last > h->data[child]) h->data[i] = h->data[child];
        else break;
    }
    h->data[i] = last;
    return m;
}

bool heap_empty(heap *h){return h->size == 0;}