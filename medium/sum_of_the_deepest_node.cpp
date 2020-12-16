/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int max_depth(Tree* root) { 
    if (root == NULL)  return 0;      
    return 1 + max(max_depth(root->left), max_depth(root->right));      
}

int sum_dp(Tree* root, int max_level) {
    if (root == NULL) return 0;      
    if (max_level == 1) return root->val;  
    return sum_dp(root->left, max_level - 1) + sum_dp(root->right, max_level - 1); 
}
    
int solve(Tree* root) {
    int depth = max_depth(root);
    return sum_dp(root, depth);
}
