
// non recursive sol.
typedef struct {
    struct TreeNode* data[10127];
    int top;
} st;

st *init(){
    st *tmp = (st *)malloc(sizeof(st));
    tmp->top = 0;
    return tmp;
}

void push(st *stack, struct TreeNode* root){
    stack->data[++stack->top] = root;
    return;
}

struct TreeNode* pop(st *stack){
    return stack->data[stack->top--];
}

bool empty(st *stack){
    return stack->top == 0;
}

int res[10127];
int resIdx;

bool isValidBST(struct TreeNode* root){
    if (!root) return true;

    resIdx = 0;    
    st *s = init();
    while (root){
        push(s, root);
        root = root->left;
    }
    while (!empty(s)){
        struct TreeNode* topNode = pop(s);
        res[resIdx++] = topNode->val;
        struct TreeNode* cur = topNode->right;
        while (cur){
            push(s, cur);
            cur = cur->left;
        }
    }

    int check = res[0];
    for (int i = 1; i < resIdx; ++i){
        if (check >= res[i]) return false;
        check = res[i];
    }
    return true;
}

// non recursive sol2.
bool isValidBST(struct TreeNode* root){
    int inorder[10127];
    int idx = 0;
    
    struct TreeNode* pre = NULL;
    while (root){
        if (root->left){
            pre = root->left;
            while (pre->right && pre->right != root){
                pre = pre->right;
            }
            if (pre->right == root){
                inorder[idx++] = root->val;
                root = root->right;
            }
            else {
                pre->right = root;
                root = root->left;
            }
        }
        else {
            inorder[idx++] = root->val;
            root = root->right;
        }
    }
    
    int check = inorder[0];
    for (int i = 1; i < idx; i++){
        if (check >= inorder[i]) return false;
        else check = inorder[i];
    }
    return true;
}

// recursive sol.
int res[10127];
int idx;

void check(struct TreeNode* root){
    if (!root) return;
    check(root->left);
    res[idx++] = root->val;
    check(root->right);
}

bool isValidBST(struct TreeNode* root){
    if (!root) return true;
    idx = 0;
    check(root);
    int increas = res[0];
    for (int i = 1; i < idx; ++i){
        if (increas >= res[i]) return false;
        increas = res[i];
    }
    return true;
}

// recursive sol2.
bool valider(struct TreeNode* root, struct TreeNode* min, struct TreeNode* max){
    if (!root) return true;
    if (min && root->val <= min->val) return false;
    if (max && root->val >= max->val) return false;
    return valider(root->left, min, root) && valider(root->right, root, max);
}

bool isValidBST(struct TreeNode* root){
    return valider(root, NULL, NULL);    
}