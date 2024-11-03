#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Queue
{
    int rear, front;
    int capacity;
    int *Array;
};
struct Queue *create(int size)
{
    struct Queue *Que = (struct Queue *)malloc(sizeof(struct Queue));
    Que->rear = -1;
    Que->front = -1;
    Que->capacity = size;
    Que->Array = (int *)calloc(Que->capacity, sizeof(int));
    return Que;
}
int isFull(struct Queue *Que)
{
    if ((Que->rear + 1) % Que->capacity == Que->front)
        return 1;
    else
        return 0;
}
int isEmpty(struct Queue *Que)
{
    if (Que->front == -1)
        return 1;
    else
        return 0;
}
void enQueue(struct Queue *Que, int data)
{
    if (isFull(Que))
        printf("\nQueue is already full!");
    else
    {
        Que->rear = (Que->rear + 1) % Que->capacity;
        Que->Array[Que->rear] = data;
        if (Que->front == -1)
            Que->front = 0;
    }
}
int deQueue(struct Queue *Que)
{
    int data;
    if (!isEmpty(Que))
    {
        data = Que->Array[Que->front];
        if (Que->rear == Que->front)
            Que->front = Que->rear = -1;
        else
            Que->front = (Que->front + 1) % Que->capacity;
    }
    return data;
}
int peek(struct Queue *Que)
{
    if (!isEmpty(Que))
        return Que->Array[Que->front];
}
int main()
{
    // your code goes here
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int per = 0, data;
        int last = 0;
        scanf("%d", &n);
        struct Queue *Que = create(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);
            enQueue(Que, data);
        }
        for (int i = 0; i < n; i++)
        {
            last = deQueue(Que);
            per = 0;
            if (isEmpty(Que))
                break;
            enQueue(Que, last);
            deQueue(Que);
            last = deQueue(Que);
            per = 1;
            if (isEmpty(Que))
                break;
            enQueue(Que, last);
            enQueue(Que, deQueue(Que));
            deQueue(Que);
        }
        printf("%d %d\n", per, last);
    }
    return 0;
}
