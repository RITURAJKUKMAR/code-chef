#include <stdio.h>
#include <stdlib.h>

#define maxSize 10
int a[maxSize];
int front = 0; // Index of the front element
int rear = -1; // Index of the rear element
int currentSize = 0;

int isEmpty()
{
    return currentSize == 0;
}

int isFull()
{
    return currentSize == maxSize;
}

int size()
{
    return currentSize;
}

void enqueue(int item)
{
    if (isFull())
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else
    {
        rear = (rear + 1) % maxSize; // Circular increment
        a[rear] = item;
        currentSize++;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value or throw an exception
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int taskList[10];
int taskListsize = 0;

void addTask(int task)
{
    int f = 1;
    for (int i = 0; i < taskListsize; i++)
    {
        if (taskList[i] == task)
        {
            f = 0;
            break;
        }
    }
    if (f==1)
        enqueue(task);
    taskList[taskListsize] = task;
    taskListsize++;
}

void displayToDoList()
{
    // Implement the method to display the current to-do list.
    int n=currentSize;
    for (int i = 0; i <n ; i++)
        printf("%d\n", dequeue());
}

int main()
{
    int n = 10;
    // Read up to 10 tasks from input and add them to the to-do list
    for (int i = 0; i < n; i++)
    {
        int task;
        scanf("%d", &task);
        addTask(task);
    }

    // Display the current to-do list
    displayToDoList();
}