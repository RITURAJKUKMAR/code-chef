#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node* create(int data)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=new;
    new->prev=new;
    return new;
}
void insertEnd(struct node **head,int data)
{
    struct node *t,*temp,*new=create(data);
    if(*head==NULL)
    {
        (*head)=new;
    }
    else
    {
        t=(*head);
        temp=(*head);
        while(t->next!=(*head))
            t=t->next;
        t->next=new;
        new->prev=t;
        new->next=temp;
        temp->prev=new;
    }
}
void deleteEnd(struct node **head)
{
    struct node *t,*temp,*back;
    if((*head)==NULL)
        printf("\nNo any data!");
    else
    {
        t=(*head);
        while(t->next!=(*head))
            t=t->next;
        back=t->prev;
        temp=t->next;
        back->next=temp;
        temp->prev=back;
        *head=t->next;
        free(t);
    }
}
void deleteBw(struct node **head,int index)
{
    int l=0,d=0;
    struct node *t,*back,*temp;
    if((*head)==NULL)
        printf("\nNo any data!");
    else
    {
        t=(*head);
        for(int i=1;t->next!=(*head);i++)
        {
            l=1;
            if(i==index)
            {
                d=1;
                back=t->prev;
                temp=t->next;
                t->prev->next=t->next;
                temp->prev=back;
                *head=temp;
                free(t);
                break;
            }
            t=t->next;
        }
        if(l==1 && d==0)
            deleteEnd(&(*head));
    }
}
void show(struct node *head)
{
    struct node *t;
    if(head==NULL)
        printf("\nNo any data!");
    else
    {
        t=head;
        printf("%d\n",t->data);
    }
}
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        {
            struct node *HEAD=NULL;
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
                insertEnd(&HEAD,i);
            while(HEAD->next!=HEAD)
                deleteBw(&HEAD,2);
            show(HEAD);
        }
    }
    return 0;
}