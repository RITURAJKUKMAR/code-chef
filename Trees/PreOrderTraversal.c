typedef struct Solution {
    void (*preOrderTraversal)(Node* root);
} Solution;

void preOrderTraversal(Node* root) {
   // Complete this
   if (root == NULL)
        return;
    printf("%d ", root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

Solution* createSolution() {
    Solution* sol = (Solution*)malloc(sizeof(Solution));
    sol->preOrderTraversal = preOrderTraversal;
    return sol;
}
