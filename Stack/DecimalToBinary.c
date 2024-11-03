#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101
char ans[MAX_SIZE]={""};
char a[MAX_SIZE];
int top = -1;

void push(char ele)
{
    if (top <= MAX_SIZE - 1)
    {
        a[++top] = ele;
    }
    else
    {
        printf("Stack is full. Cannot push: %d\n", ele);
    }
}

int pop()
{
    if (top >= 0)
    {
        int ele = a[top];
        top--;
        return ele;
    }
    else
    {
        printf("Stack is empty. Cannot pop.\n");
    }
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top >= MAX_SIZE;
}

char *decimalToBinary(int decimal)
{
    while (decimal > 0)
    {
        // Update the code below
        if (decimal % 2 == 0)
        {
            push('0');
            decimal = decimal / 2;
        }
        else
        {
            push('1');
            decimal = decimal / 2;
        }
    }
    if (isEmpty())
    {
        return "0"; // Special case for decimal = 0
    }
    int i = 0;
    while (!isEmpty())
    {
        ans [i] = pop();
        i++;
    }

    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int decimal;
        scanf("%d", &decimal);
        char *ans = decimalToBinary(decimal);
        while (*ans != '\0')
        {
            printf("%c", *ans);
            // move the ans pointer to the next memory location
            ans++;
        }
        printf("\n");
    }
}
