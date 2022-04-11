
int sum;

void tra(struct TreeNode* root){
    if (!root) return;
    tra(root->right);
    root->val += sum;
    sum = root->val;
    tra(root->left);
    
}

struct TreeNode* convertBST(struct TreeNode* root){
    sum = 0;
    tra(root);
    return root;
}
