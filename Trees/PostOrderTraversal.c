// typedef struct Node {
//     int val;
//     struct Node* left;
//     struct Node* right;
// } Node;

// Function to perform post-order traversal
void postOrderTraversal(Node* root) {
    // Complete this
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->val);
}
