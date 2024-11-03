#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

// Function to create a stack with a given capacity
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

int isOperant(char exp)
{
    if (exp <= '9' && exp >= '0')
        return 1;
    else
        return 0;
}
void pushOperant(struct Stack *stack, char exp)
{
    switch (exp)
    {
    case '0':
        push(stack, 0);
        break;
    case '1':
        push(stack, 1);
        break;
    case '2':
        push(stack, 2);
        break;
    case '3':
        push(stack, 3);
        break;
    case '4':
        push(stack, 4);
        break;
    case '5':
        push(stack, 5);
        break;
    case '6':
        push(stack, 6);
        break;
    case '7':
        push(stack, 7);
        break;
    case '8':
        push(stack, 8);
        break;
    case '9':
        push(stack, 9);
        break;
    }
}
int solution(char o, int n1, int n2)
{
    switch (o)
    {
    case '+':
        return n2 + n1;
    case '-':
        return n2 - n1;
    case '*':
        return n2 * n1;
    case '/':
        return n2 / n1;
    }
}
int evaluateSuffixExpression(char expresstion[])
{
    struct Stack *stack = NULL;
    int ans = 0, n1, n2, l = strlen(expresstion);
    char o;
    stack=createStack(l);
    for (int i = 0; i < l; i++)
    {
        if (isOperant(expresstion[i]))
            pushOperant(stack,expresstion[i]);
        else
        {
            o = expresstion[i];
            n1 = pop(stack);
            n2 = pop(stack);
            ans = solution(o, n1, n2);
            push(stack,ans);
        }
    }
    ans = pop(stack);
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        char suffix[n];
        scanf("%s", suffix);
        int result = evaluateSuffixExpression(suffix);

        printf("%d\n", result);
    }
}
