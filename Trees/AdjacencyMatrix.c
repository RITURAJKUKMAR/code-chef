#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct AM
{
    int data;
    struct AM *left,*right;
};
struct AM *create(int data)
{
    struct AM *New=(struct AM*)malloc(sizeof(struct AM));
    New->left=New->right=NULL;
    New->data=data;
    return New;
}
void insertLeft(struct AM **root,int rData,int data)
{
    if(*root==NULL)
        *root=create(rData);
    else
    {
        if((*root)->data==rData)
            insertLeft(&root,rData,data);
    }
}
int main()
{
    struct AM *root=NULL;
    return 0;
}
// not final