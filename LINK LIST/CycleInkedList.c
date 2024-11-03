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
    newNode->data=data;
    newNode->next=newNode;
    return newNode;
}
void insert(struct node **s)
{
    int data;
    struct node *newNode,*t,*temp;
    scanf("%d",&data);
    newNode=creat(data);
    if((*s)==NULL)
        (*s)=newNode;
    else
    {
        t=(*s);
        temp=t->next;
        t->next=newNode;
        newNode->next=temp;
        (*s)=newNode;
    }
    
}
int show(struct node *s,int n)
{
    int val;
    struct node *temp=s->next,*t;
    while(n--)
    {    
        val=temp->data;
        temp=temp->next;
    }
    return val;
}
int main() {
	// your code goes here
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    {
	        struct node *head=NULL;
    	    int n,m;
    	    scanf("%d",&n);
    	    while(n--)
    	        insert(&head);
    	    scanf("%d",&m);
            printf("%d\n",show(head,m));
	    }
	}
	return 0;

}

