/*
  Reverse a Linked List
  Question 42 of 987

  https://binarysearch.com/problems/Reverse-a-Linked-List
*/

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    if (node == NULL) return node;
    LLNode* prev = NULL;
    LLNode* curr = node;
    LLNode* next = curr->next;
    if (next == NULL) return node;
    do {
        LLNode* nnext = next->next;
        curr->next = prev;
        next->next = curr;

        prev = curr;
        curr = next;
        next = nnext;
    } while (next != NULL);
    return curr;
}
