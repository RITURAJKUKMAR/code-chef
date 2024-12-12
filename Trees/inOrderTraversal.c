// typedef struct Node {
//     int val;
//     struct Node* left;
//     struct Node* right;
// } Node;

void inOrderTraversal(Node* root) {
   // Complete this
   if (root == NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}
