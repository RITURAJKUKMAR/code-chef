#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data, status;
    struct node *next;
};
struct Queue
{
    struct node *data;
    struct Queue *next;
};
struct Queue *createQueue(struct node *data)
{
    struct Queue *Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->data = data;
    Q->next = NULL;
    return Q;
}
int isEmpty(struct Queue *Q)
{
    return Q == NULL;
}
void push(struct Queue **Q, struct node *data)
{
    struct Queue *t = (*Q);
    if ((*Q) == NULL)
        (*Q) = createQueue(data);
    else
    {
        while (t->next != NULL)
            t = t->next;
        t->next = createQueue(data);
    }
}
struct node *pop(struct Queue **Q)
{
    struct node *temp = (*Q)->data;
    if (Q != NULL)
    {
        temp = (*Q)->data;
        struct Queue *t = (*Q);
        if ((*Q)->next == NULL)
            (*Q) = NULL;
        else
            (*Q) = t->next;
        free(t);
    }
    return temp;
}
struct node *create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->status = 0;
    newNode->next = NULL;
    return newNode;
}
void insert(struct node **s, int data)
{
    if ((*s) == NULL)
        (*s) = create(data);
    else
    {
        struct node *t = (*s);
        while (t->next != NULL)
            t = t->next;
        t->next = create(data);
    }
}
void show(struct node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct node *t = (arr[i]);
        if (t != NULL)
        {
            while (t->next != NULL)
            {
                t = t->next;
                printf("%d ", t->data);
            }
            printf("\n");
        }
    }
}
void dfs(struct node *arr[], int n)
{
    struct node *temp;
    struct Queue *Q = NULL;
    for (int i = 0; i < n; i++)
    {
        temp = (arr[i]);
        if (temp->status != 1 && temp->next != NULL)
        {
            push(&Q, temp);
            temp->status = 1;
        }
        while (!isEmpty(Q))
        {
            temp = pop(&Q);
            printf(" %d ", temp->data);
            if (temp->status != 1 && temp->next != NULL)
            {
                push(&Q, temp->next);
                temp->status = 1;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    struct node *arr[n];
    int l, m;
    for (int i = 0; i < n; i++)
        arr[i] = create(i);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &l, &m);
        for (int i = 0; i < n; i++)
            if (arr[i]->data == l)
                insert(&(arr[i]->next), m);
    }
    show(arr, n);
    dfs(arr, n);
    return 0;
}
// not final