// typedef struct Node {
//     int val;
//     struct Node* left;
//     struct Node* right;
// } Node;

int max(int a,int b)
{
    return a>b?a:b;
}
int heightOfBinaryTree(Node* root) {
    // Complete this
    if(root==NULL)
        return -1;
    int left=heightOfBinaryTree(root->left);
    int height=heightOfBinaryTree(root->right);
    return max(left,height)+1;
}