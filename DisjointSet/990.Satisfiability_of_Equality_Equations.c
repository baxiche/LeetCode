

void make_set(int parent[]){
    for (int i = 0; i < 26; ++i) parent[i] = i;
}

int find_set(int parent[], int x){
    int root = x;
    while (parent[root] != root) 
        root = parent[root];
    
    int old = parent[x];
    while (old != root){
        parent[x] = root;
        x = old;
        old = parent[old];
    }
    
    return root;
}

void union_set(int parent[], int p, int q){
    int rootp = find_set(parent, p);
    int rootq = find_set(parent, q);
    if (rootp == rootq) return;
    
    parent[rootq] = rootp;
}

bool equationsPossible(char ** eqs, int es){
    int parent[26];
    make_set(parent);
    for (int i = 0; i < es; ++i){
        if (eqs[i][1] == '=') 
            union_set(parent, eqs[i][0] - 'a', eqs[i][3] - 'a');
    }
    for (int i = 0; i < es; ++i){
        if (eqs[i][1] == '!'){
            if (find_set(parent, eqs[i][0] - 'a') == find_set(parent, eqs[i][3] - 'a'))
                return false;
        }
    }

    return true;
}