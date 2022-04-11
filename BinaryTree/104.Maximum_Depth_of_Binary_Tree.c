/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void lev(struct TreeNode* root, int level){
    if (!root) return;
    printf("val = %d, level = %d\n", root->val, level);
    lev(root->left, level + 1);
    lev(root->right, level + 1);
}

int count(struct TreeNode* root){
    if (!root) return 0;
    
    int left = count(root->left);
    int right = count(root->right);
    
    printf("node %d has %d subnodes\n", root->val, left + right);
    return 1 + left + right;
}

int res;
int dep;

void tra(struct TreeNode* root){
    if (!root) return;
    
    ++dep;
    res = (res > dep)? res : dep;
    tra(root->left);
    tra(root->right);
    --dep;
}

int maxDepth(struct TreeNode* root){
    res = dep = 0;
    tra(root);
    return res;
}

//sol 2

int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + ((left > right)? left : right);
} 