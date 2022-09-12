

#include <iostream>
#include <deque>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 1;
        deque<TreeNode*> deq;
        deq.push_back(root);
        while (!deq.empty()){
            int sz = (int)deq.size();
            for (int i = 0; i < sz; ++i){
                TreeNode *cur = deq.front();
                deq.pop_front();
                
                if (!cur->left && !cur->right) return depth;

                if (cur->left) deq.push_back(cur->left);
                if (cur->right) deq.push_back(cur->right);
            }
            ++depth;
        }

        return -1;
    }
};

int main(){
    struct TreeNode* root = new struct TreeNode;
    root->val = -1;
    root->left = new struct TreeNode;
    root->left->val = 1;
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right = nullptr;
    minDepth(root);
}