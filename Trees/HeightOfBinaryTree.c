#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Binary
{
    int data;
    struct Binary *left, *right;
};
struct Binary *create(int data)
{
    struct Binary *new = (struct Binary *)malloc(sizeof(struct Binary));
    new->left = new->right = NULL;
    new->data = data;
    return new;
}
struct Binary *find(struct Binary *root, int rootData)
{
    if (root == NULL)
        return root;
    find(root->left, rootData);
    if(root->data==rootData)
        return root;
    find(root->right, rootData);
}
void insert(struct Binary **root, int rootData, int data, char d)
{
    struct Binary *findRoot = NULL;
    if (*root == NULL)
    {
        (*root) = create(rootData);
        if (d == 'L')
            (*root)->left = create(data);
        else
            (*root)->right = create(data);
    }
    else
    {
        findRoot = find((*root), rootData);
        if (d == 'L')
            findRoot->left = create(data);
        else
            findRoot->right = create(data);
    }
}
void inorder(struct Binary *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}
int height(struct Binary *root)
{
    static int count=0;
    if(root==NULL)
        return count;
    count++;
    height(root->left);
    height(root->right);
}
int main()
{
    struct Binary *root = NULL;
    int t;
    scanf("%d", &t);
    t--;
    while (t--)
    {
        int rootData, data;
        char d;
        scanf("%d%d %c", &rootData, &data, &d);
        insert(&root, rootData, data, d);
    }
    printf("\nInorder : ");
    inorder(root);
    printf("\n %d\n",height(root));
    return 0;
}
// not final