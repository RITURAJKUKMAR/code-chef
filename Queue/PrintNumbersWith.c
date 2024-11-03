#include <stdio.h>
#include <stdlib.h>

#define maxSize 101
int a[maxSize];
int front=0; // Index of the front element
int rear=-1;  // Index of the rear element
int currentSize=0;

int isEmpty(){
    return currentSize==0;
}

int isFull(){
    return currentSize==maxSize;
}

int size(){
    return currentSize;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    rear=(rear+1)%maxSize; // Circular increment
    a[rear]=item;
    currentSize++;
}

int dequeue(){
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value or throw an exception
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int main(){
    int n=10;
    // Your code goes here
    for(int i=1;i<=10;i++)
    {
        printf("%d ",i);
        i++;
        enqueue(i);
    }
    for(int i=0;i<5;i++)
        printf("%d ",dequeue());
    return 0;
}