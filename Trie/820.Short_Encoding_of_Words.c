
#define idx(c) (c - 'a')

typedef struct node{
    struct node *child[26];
} node;

node *new(){
    node *t = (node*)malloc(sizeof(node));
    for (int i = 0; i < 26; ++i) t->child[i] = NULL;
    return t;
}

void dfs(node *root, int *sum, int pathSum){    
    if (!root) return;
    
    int nullSum = 26;
    for (int i = 0; i < 26; ++i){
        if (root->child[i]){
            --nullSum;
            ++pathSum;
            dfs(root->child[i], sum, pathSum);
            --pathSum;
        }
    }
    if (nullSum == 26){
        (*sum) += pathSum + 1;
    }
}

int minimumLengthEncoding(char ** words, int n){
    node *root = new();
    node *cur = root;
    for (int i = 0; i < n; ++i){
        for (int j = strlen(words[i]) - 1; j >= 0; --j){
            if (!cur->child[idx(words[i][j])])
                cur->child[idx(words[i][j])] = new();
            cur = cur->child[idx(words[i][j])];
        }
        cur = root;
    }
    int sum = 0;
    dfs(root, &sum, 0);

    return sum;
}