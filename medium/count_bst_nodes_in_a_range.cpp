/*
  Count BST Nodes in a Range
  Question 139 of 931

  https://binarysearch.com/problems/Count-BST-Nodes-in-a-Range
*/

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, int lo, int hi) {
    if (!root) return 0; 
    if (root->val == hi && root->val == lo) 
        return 1; 
    if (root->val <= hi && root->val >= lo) 
         return 1 + solve(root->left, lo, hi) + 
                    solve(root->right, lo, hi); 
    else if (root->val < lo) 
         return solve(root->right, lo, hi); 
    else return solve(root->left, lo, hi);   
}
