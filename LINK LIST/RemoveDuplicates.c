#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* creat(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->next=newNode;
    newNode->data=data;
    return newNode;
}
void insert(struct node **s)
{
    int data;
    struct node *t,*newNode;
    scanf("%d",&data);
    newNode=creat(data);
    if(*s==NULL)
        (*s)=newNode;
    else
    {
        t=(*s);
        newNode->next=t->next;
        t->next=newNode;
        (*s)=newNode;
    }
}
void show(struct node **s)
{
    struct node *b,*t=(*s)->next;
    if(t!=NULL)
    {
        printf("%d",t->data);
        while(t!=(*s))
        {
            b=t;
            t=t->next;
            if(b->data!=t->data)
                printf(" %d",t->data);
        }
    }
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    {
	        struct node *head=NULL;
    	    int m,n;
    	    scanf("%d",&n);
    	    m=n;
    	    while(n--)
    	        insert(&head);
    	    show(&head);
            printf("\n");
        }
	}
    return 0;
}