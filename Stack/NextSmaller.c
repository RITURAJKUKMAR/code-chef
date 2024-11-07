#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

int main()
{
    // Write your code here
    struct Stack *s = NULL;
    int n;
    scanf("%d", &n);
    s = createStack(n);
    int j=0, f = 1, ans[n];
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = n - 1; i >= 0; i--)
        push(s, arr[i]);
    for (int k = 0; k < n; k++)
    {
        f=1;
        for (int i = k; i < n; i++)
        {
            if (arr[i + 1] <= peek(s))
            {
                f = 0;
                ans[j++] = arr[i+1];
                break;
            }
        }
        if (f==1)
            ans[j++] = -1;
        pop(s);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}