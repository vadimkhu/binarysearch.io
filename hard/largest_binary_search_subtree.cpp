/*
  Largest Binary Search Subtree
  Question 129 of 913
  
  https://binarysearch.com/problems/Largest-Binary-Search-Subtree 
*/

// geeksforgeeks solution

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
 
struct Info {
    Tree* root;
    int sz; // Size of subtree 
    int max; // Min value in subtree 
    int min; // Max value in subtree 
    int ans; // Size of largest BST which 
    // is subtree of current node 
    bool isBST; // If subtree is BST 
};  

Info largestBSTBT(Tree* root) 
{ 
    if (root == NULL) 
        return {root, 0, INT_MIN, INT_MAX, 0, true}; 
    if (root->left == NULL && root->right == NULL) 
        return {root, 1, root->val, root->val, 1, true}; 
  
    Info l = largestBSTBT(root->left); 
    Info r = largestBSTBT(root->right); 
  
    Info ret; 
    ret.sz = (1 + l.sz + r.sz); 
  
    if (l.isBST && r.isBST && l.max < root->val && 
            r.min > root->val) {
        ret.root = root;
        ret.min = min(l.min, min(r.min, root->val)); 
        ret.max = max(r.max, max(l.max, root->val)); 
  
        // Update answer for tree rooted under 
        // current 'root' 
        ret.ans = ret.sz; 
        ret.isBST = true; 
  
        return ret; 
    } 
  
    if (l.ans > r.ans) {
        ret.root = l.root;
        ret.ans = l.ans;
    } else {
        ret.root = r.root;
        ret.ans = r.ans;
    }
    ret.isBST = false; 
    return ret; 
} 

Tree* solve(Tree* root) {
    return largestBSTBT(root).root;  
}

