/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max;

int *tra(struct TreeNode* root){
    if (!root){
        int *res = (int*)malloc(4 * sizeof(int));
        res[0] = 1;
        res[1] = 49736;
        res[2] = -49736;
        res[3] = 0;
        return res;
    }
    
    int *left = tra(root->left);
    int *right = tra(root->right);
    
    int *res = (int*)malloc(4 * sizeof(int));
    if (left[0] && right[0] && root->val > left[2] && root->val < right[1]){
        res[0] = 1;
        res[1] = (left[1] < root->val)? left[1] : root->val; 
        res[2] = (right[2] > root->val)? right[2] : root->val;
        res[3] = root->val + left[3] + right[3];
        max = (max > res[3])? max : res[3];
    }
    else res[0] = 0;
    
    return res;
}

int maxSumBST(struct TreeNode* root){
    max = 0;
    tra(root);
    return max;
}