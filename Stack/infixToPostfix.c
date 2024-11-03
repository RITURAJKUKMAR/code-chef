#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 400

struct Stack {
    int maxSize;
    char stackArray[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack, int size) {
    stack->maxSize = size;
    stack->top = -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top < stack->maxSize - 1) {
        stack->stackArray[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->stackArray[stack->top--];
    }
    return ' ';
}

char peek(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->stackArray[stack->top];
    }
    return ' ';
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void infixToPostfix(char* infix, char* postfix) {
    // Write your code here
    struct Stack s;
    int j=0,n=strlen(infix);
    initStack(&s,n);
    for(int i=0;i<n;i++)
    {
        if(*(infix+i)=='(')
            push(&s,*(infix+i));
        else if('+'==*(infix+i) ||'-'==*(infix+i) ||'*'==*(infix+i) ||'/'==*(infix+i) ||'^'==*(infix+i)  )
        {
            if(peek(&s)=='(')
                push(&s,*(infix+i));
            else
                push(&s,*(infix+i));
        }
        else if(*(infix+i)==')')
        {
            char c=pop(&s);
            while(c!='(')
            {
                *(postfix+(j++))=c;
                c=pop(&s);
            }
        }
        else if(((*(infix+i))>='a' && (*(infix+i))<='z') || ((*(infix+i))>='A' && (*(infix+i))<='Z') )
            *(postfix+(j++))=*(infix+i);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); // Consume the newline

    while(t--){
        char infixExpression[MAX_SIZE];
        char postfixExpression[MAX_SIZE]={""};
        fgets(infixExpression, MAX_SIZE, stdin);
        infixToPostfix(infixExpression, postfixExpression);
        printf("%s\n", postfixExpression);
    }

    return 0;
}