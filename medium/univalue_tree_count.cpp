/*
  Univalue Tree Count
  Question 11 of 932

  https://binarysearch.com/problems/Univalue-Tree-Count
*/

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
 bool countUnivalueTree(Tree* root, int &count) { 
    if (root == NULL) 
       return true; 
  
    bool left = countUnivalueTree(root->left, count); 
    bool right = countUnivalueTree(root->right, count); 
  
    if (left == false || right == false) 
       return false; 
  
    if (root->left && root->val != root->left->val) 
        return false; 
  
    if (root->right && root->val != root->right->val) 
        return false; 
  
    count++; 
    return true; 
} 

int solve(Tree* root) {
    int count = 0;
    countUnivalueTree(root, count);
    return count;
}
