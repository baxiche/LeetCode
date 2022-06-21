
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define LEAF_ 0
#define INSTALL_ 1
#define MONITOR 2
#define N_MONITOR 3

int rec(struct TreeNode* root, int par, int *res){
    if (!root) return LEAF_;

    int l = rec(root->left, 1, res);
    int r = rec(root->right, 1, res);

    if (l == LEAF_ && r == LEAF_){
        if (par) return N_MONITOR;

        ++(*res);
        return INSTALL_;
    }

    if (l == N_MONITOR || r == N_MONITOR){
        ++(*res);
        return INSTALL_;
    }

    if (l == INSTALL_ || r == INSTALL_){
        return MONITOR;
    }
    
    if (par) return N_MONITOR;

    ++(*res);
    return INSTALL_; 
}

int minCameraCover(struct TreeNode* root){
    int res = 0;
    rec(root, 0, &res);
    return res;
}