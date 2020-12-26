/*
  Kth Smallest in a Binary Search Tree
  Question 72 of 931
  
  https://binarysearch.com/problems/Kth-Smallest-in-a-Binary-Search-Tree
*/
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* kthSmallest(Tree* root, int& k) {
    if (root == NULL)
        return NULL;
    Tree* left = kthSmallest(root->left, k);
    if (left != NULL)
        return left;
    k--;
    if (k < 0)
        return root;
    return kthSmallest(root->right, k);
}

int solve(Tree* root, int k) {
    int ans = 0;
    Tree* node = kthSmallest(root, k);
    if (node != NULL) return node->val;
    return ans;
}
