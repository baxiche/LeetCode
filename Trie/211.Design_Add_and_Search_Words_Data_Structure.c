
#define idx(c) (c - 'a')

typedef struct WordDictionary{
    int count;
    struct WordDictionary *child[26];
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
    WordDictionary *t = (WordDictionary *)malloc(sizeof(WordDictionary));
    for (int i = 0; i < 26; ++i)
        t->child[i] = NULL;
    
    t->count = 0;
    return t;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])])
            obj->child[idx(word[i])] = wordDictionaryCreate(); 

        obj = obj->child[idx(word[i])];
    }
    ++obj->count;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
    for (int i = 0, len = strlen(word); i < len; ++i){
        if (!obj->child[idx(word[i])]) return false;

        obj = obj->child[idx(word[i])];
    }
    return obj->count;
}

void wordDictionaryFree(WordDictionary* obj) {
    return;
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/