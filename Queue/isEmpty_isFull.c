#include <stdio.h>
#include <stdbool.h>

#define maxSize 101
int a[maxSize];
int front = 0; // Index of the front element
int rear = -1;  // Index of the rear element
int currentSize = 0;

bool isEmpty(){
    // Complete this function
    return currentSize == 0;
}

bool isFull(){
    // Complete this function
    return currentSize == maxSize;
}

int size(){
    // Complete this function
    return currentSize;
}