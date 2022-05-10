#include <stdio.h>

int read(){
    int n = 0;
    char c = getchar();
    while (c < '0' || c > '9'){
        c = getchar();
    }
    while (c >= '0' && c <= '9'){
        n = (n * 10) + (c - '0');
        c = getchar();
    }
    return n;
}

void make_set(int parent[], int n){
    for (int i = 0; i < n; ++i){
        parent[i] = i;
    }
}

int find_set(int parent[], int x){
    int root = x;
    while (parent[root] != root) 
        root = parent[root];
    
    int pre_parent = parent[x];
    while (pre_parent != root){
        parent[x] = root;
        x = pre_parent;
        pre_parent = parent[x];
    }

    return root;
}

void union_set(int parent[], int p, int q){
    int rootp = find_set(parent, p);
    int rootq = find_set(parent, q);
    if (rootp == rootq) return;

    parent[rootq] = rootp;
}

int connected_set(int parent[], int p, int q){
    int rp = find_set(parent, p);
    int rq = find_set(parent, q);
    return (rp == rq)? 1 : 0;
}

int main(){
    int n; n = read();
    int parent[n];
    make_set(parent, n);

}