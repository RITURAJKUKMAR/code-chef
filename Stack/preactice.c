#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, char value) {
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=value;
    if (newNode == NULL) {
        exit(1);  // Exit if memory allocation fails
    }
    // Update your code below this newline
    else
    {
        newNode->next=stack->top;
        stack->top = newNode;
    }
}

char pop(Stack* stack) {
    Node *t;
    char c;
    if (isEmpty(stack)) {
        return '\0';
    }
    // Update your code below this line
    else
    {
        t=stack->top;
        c=stack->top->data;
        stack->top=stack->top->next;
    }
    return c;
}

void reverseString(char* str) {
    int len = strlen(str);
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < len; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; i < len; i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[1001];  // 1000 characters + 1 for null terminator

    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;  // Adjust length after removing newline
        }

        reverseString(str);
        
        // Print without using printf to avoid any automatic space addition
        fwrite(str, sizeof(char), len, stdout);
    }

    return 0;
}