#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
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
    return 0;
}