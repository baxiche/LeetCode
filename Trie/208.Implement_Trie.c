#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define idx(c) (c - 'a')

typedef struct Trie{
    int count;
    struct Trie *child[26];
} Trie;

Trie* trieCreate() {
    Trie *t = (Trie *)malloc(sizeof(Trie));
    t->count = 0;
    for (int i = 0; i < 26; ++i)
        t->child[i] = NULL;
    return t;
}

void trieInsert1(Trie* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])]){
            obj->child[idx(word[i])] = trieCreate();
        }
        obj = obj->child[idx(word[i])];
    }
    ++obj->count;
}

void rec1(Trie *obj, char *word, int i, int len){
    if (i == len){
        ++obj->count;
        return;
    }

    if (!obj->child[idx(word[i])])
        obj->child[idx(word[i])] = trieCreate();

    rec1(obj->child[idx(word[i])], word, i + 1, len);
}

void trieInsert2(Trie* obj, char *word){
    int len = strlen(word);
    rec1(obj, word, 0, len);
}

Trie *rec2(Trie *obj, char *word, int i, int len){
    if (!obj){
        obj = trieCreate();
    }

    if (i == len){
        ++obj->count;
        return obj;
    }

    obj->child[idx(word[i])] = rec2(obj->child[idx(word[i])], word, i + 1, len);
    return obj;
}

void trieInsert(Trie *obj, char *word){
    int len = strlen(word);
    obj = rec2(obj, word, 0, len);
}

bool trieSearch(Trie* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])]) 
            return false;
        obj = obj->child[idx(word[i])];
    }
    
    return obj->count;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    for (int i = 0, len = strlen(prefix); i < len; ++i){
        if (!obj->child[idx(prefix[i])]) 
            return false;
        obj = obj->child[idx(prefix[i])];
    }
    return true;
}

void trieFree(Trie* obj) {
    return;
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/

int main(){
    Trie* obj = trieCreate();
    trieInsert(obj, "apple");
    assert(trieStartsWith(obj, "apple"));
    assert(trieSearch(obj, "apple"));
}