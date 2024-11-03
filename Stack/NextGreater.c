#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Stack* stack = createStack(n);

    // Initialize the NGE array
    int* nge = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
    }

    // Iterating the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop till the top element is smaller than current
        while (!isEmpty(stack) && peek(stack) < arr[i]) {
            pop(stack);
        }

        if (!isEmpty(stack)) {
            nge[i] = peek(stack);
        }

        // Push the current element to stack
        push(stack,arr[i]);
    }

    // Print the NGE array
    for (int i = 0; i < n; i++) {
        printf("%d ", nge[i]);
    }
    printf("\n");

    free(arr);
    free(stack->array);
    free(stack);
    free(nge);

    return 0;
}
