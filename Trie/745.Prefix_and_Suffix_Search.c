#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define idx(c) (c - 'a')

typedef struct node{
    int count;
    struct node *child[26];
} node;

node *root;

node *new(){
    node *t = (node *)malloc(sizeof(node));
    t->count = 0;
    for (int i = 0; i < 26; ++i)
        t->child[i] = NULL;
    return t;
}

void insert(char str[]){
    node *cur = root;
    for (int i = 0, len = strlen(str); i < len; ++i){
        if (!cur->child[idx(str[i])])
            cur->child[idx(str[i])] = new();
        
        cur = cur->child[idx(str[i])];
    }
    ++(cur->count);
}

void delete(char str[]){
    node *cur = root;
    for (int i = 0, len = strlen(str); i < len; ++i){
        if (!cur->child[idx(str[i])])
            return;
        
        cur = cur->child[idx(str[i])];
    }
    --(cur->count);
}

bool search(char str[]){
    node *cur = root;
    for (int i = 0, len = strlen(str); i < len; ++i){
        if (!cur->child[idx(str[i])]) 
            return false;
        cur = cur->child[idx(str[i])];
    }
    for (int i = 0; i < 26; ++i){
        if (cur->child[i]) return false;
    }
    return cur->count;
}

void release(node *root){
    if (!root) return;

    for (int i = 0; i < 26; ++i){
        if (root->child[i]){
            release(root->child[i]);
            free(root->child[i]);
        }
    }
}

int main(){
    root = new();
    insert("apple");
    assert(search("apple"));
    delete("apple");
    assert(!search("apple"));

    release(root);

}

