int maxNodeInBST(Node * root) {
    //code here
    struct Node * t = root;
    while (t -> right != NULL)
        t = t -> right;
    return t -> val;
}