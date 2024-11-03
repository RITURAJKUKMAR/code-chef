#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int top, capacity;
    int *Array;
};
struct Stack *create(int size)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = size;
    s->Array = (int *)calloc(s->capacity, sizeof(int));
    return s;
}
int isFull(struct Stack *s)
{
    if ((s->top + 1) == s->capacity)
        return 1;
    else
        return 0;
}
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
void push(struct Stack *s, int data)
{
    if (!isFull(s))
    {
        s->top++;
        s->Array[s->top] = data;
    }
}
int pop(struct Stack *s)
{
    int data;
    if (!isEmpty(s))
    {
        data = s->Array[s->top];
        s->top--;
    }
    return data;
}
int peek(struct Stack *s)
{
    if (!isEmpty(s))
        return s->Array[s->top];
}
int small(struct Stack *s, int arr[], int n, int i)
{
    int data = -1;
    int a = pop(s);
    for (i = i + 1; i < n; i++)
    {
        if (a >= arr[i])
        {
            data = 1;
            break;
        }
    }
    return data;
}
int main()
{
    struct Stack *s;
    int n, data;
    scanf("%d", &n);
    s = create(5);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i=n-1;i>=0;i--)
        push(s,arr[i]);
    for (int i = 0; i < n; i++)
        arr[i]=small(s, arr, n, i);
    for (int i =0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}