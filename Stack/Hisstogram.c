// Last question of last module of stack
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
    stack->array = (int *)malloc((stack->capacity) * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack, int N)
{
    return stack->top == N - 1;
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

long max(long a, long b)
{
    return (a > b) ? a : b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        // Write your code here
        int n;
        scanf("%d", &n);
        struct Stack *s = createStack(n);
        push(s, 0);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            int left = i;
            while (arr[left] >= arr[i] && left >= 0)
                left--;
            int right = i;
            while (arr[right] >= arr[i] && right < n)
                right++;
            maxArea = (right - left - 1) * arr[i];
            if (peek(s) < maxArea)
            {
                pop(s);
                push(s, maxArea);
            }
        }
        maxArea=pop(s);
        free(s->array);
        free(s);
        printf("%d\n", maxArea);
    }
    return 0;
}