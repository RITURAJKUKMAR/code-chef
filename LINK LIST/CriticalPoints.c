#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node* creat(int data)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=newNode;
    newNode->prev=newNode;
    return newNode;
}
void insert(struct node **s)
{
    int data;
    struct node *newNode,*t,*temp;
    scanf("%d",&data);
    newNode=creat(data);
    if(*s==NULL)
        (*s)=newNode;
    else
    {
        t=(*s);
        temp=t->next;
        t->next=newNode;
        newNode->prev=t;
        newNode->next=temp;
        temp->prev=newNode;
    }
}
int critical(struct node *s)
{
    int criti=0;
    struct node *t;
    {
        t=s->next;
        
        // if(t->prev->data < t->data > t->next->data)
        //     criti++;
        while(t->next!=s)
        {
            t=t->next;
            if((t->prev->data < t->data) && (t->data > t->next->data))
                criti++;
            else if((t->prev->data > t->data) && (t->data < t->next->data))
                criti++;
        }
    }
    return criti;
}
int main() {
	// your code goes here
	struct node *head=NULL;
	int n;
	scanf("%d",&n);
	while(n--)
	    insert(&head);
	int criti=critical(head);
	printf("%d ",criti);
    return 0;
}

