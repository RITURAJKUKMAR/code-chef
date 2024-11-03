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
    scanf("%d",&data);
    struct node *newNode,*t,*temp;
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
int middle(struct node **s,int n)
{
    int m;
    struct node *t;
    t=(*s)->next;
    while(n--)
    {
        m=t->data;
        t=t->next;
    }
    return m;
}
int main() {
	// your code goes here
	int t,m;
	scanf("%d",&t);
	while(t--)
	{
	    {
	        struct node *head=NULL;
	        int n;
	        scanf("%d",&n);
	        m=n;
	        while(n--)
	            insert(&head);
	        printf("%d\n",middle(&head,((m/2)+1)));
	    }
	}
	return 0;

}

