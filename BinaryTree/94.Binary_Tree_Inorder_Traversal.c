// O(n) extra space
int* inorderTraversal(struct TreeNode* root, int* sz){
    *sz = 0;
    int* res = (int*)malloc(sizeof(int) * 127);
    struct TreeNode* s[127];
    int top = 0;
    
    while (root || top > 0){
        while (root){
            s[top++] = root;
            root = root->left;
        }
        root = s[--top];
        res[(*sz)++] = root->val;
        root = root->right;
    }
    return res;
}

// O(1) extra space
int* inorderTraversal(struct TreeNode* root, int* sz){
    *sz = 0;
    int* res = (int*)malloc(sizeof(int) * 127);
    struct TreeNode* pre = NULL;
    
    while (root){
        if (root->left){
            pre = root->left;
            while (pre->right && pre->right != root){
                pre = pre->right;
            }
            if (!pre->right){
                pre->right = root;
                root = root->left;
            }
            else {
                res[(*sz)++] = root->val;
                root = root->right;
            }
        }
        else {
            res[(*sz)++] = root->val;
            root = root->right;
        }
    }
    
    return res;
}