#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int front, rear;
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
    if (!isFull(Que))
    {
        if (Que->front == -1)
            Que->front = 0;
        Que->rear = (Que->rear + 1) % Que->capacity;
        Que->Array[Que->rear] = data;
    }
}
int deQueue(struct Queue *Que)
{
    int data;
    if (!isEmpty(Que))
    {
        data = Que->Array[Que->front];
        Que->front = (Que->front + 1) % Que->capacity;
        if (Que->rear == Que->front)
            Que->front = Que->rear = -1;
        return data;
    }
}
void traverse(struct Queue *Que)
{
    int f = Que->front;
    int r = Que->rear;
    while (f != r)
    {
        printf("%d ", Que->Array[f]);
        f = (f + 1) % Que->capacity;
    }
    printf("%d\n", Que->Array[f]);
}
int main()
{
    // your code goes here
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, data, k;
        scanf("%d%d", &n,&k);
        struct Queue *Que = create(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &data);
            enQueue(Que, data);
        }
        for (int i = 0; i < k; i++)
            enQueue(Que, deQueue(Que));
        traverse(Que);
    }

    return 0;
}