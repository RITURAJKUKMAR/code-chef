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

    struct Stack *s = createStack(t);
    while (t--)
    {
        // Write your code here
        int n;
        push(s,1);
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        int width = arr[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int height, width = (j - i) + 1;
                if (arr[i] == max(arr[i], arr[j]))
                    height = arr[j];
                else
                    height = arr[i];
                if (peek(s) < height * width)
                {
                    pop(s);
                    push(s, height * width);
                }
            }
        }
        printf("%d\n",pop(s));
    }
    return 0;
}

// not final