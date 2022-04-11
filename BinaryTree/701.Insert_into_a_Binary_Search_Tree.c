/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (!root){
        struct TreeNode *cur = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        cur->val = val;
        cur->left = cur->right = NULL;
        return cur;
    }
    if (val > root->val) root->right = insertIntoBST(root->right, val);
    else root->left = insertIntoBST(root->left, val);
    return root;
}