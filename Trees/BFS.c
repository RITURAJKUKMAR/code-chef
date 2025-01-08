#include <stdio.h>
#include <stdlib.h>


struct QueueNode {
    int data;
    struct QueueNode* next;
};


struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};


struct QueueNode* newQueueNode(int data) {
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


void enqueue(struct Queue* q, int data) {
    struct QueueNode* node = newQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}


int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}


int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    
    int** tree = (int**)malloc((n + 1) * sizeof(int*));
    int* treeSize = (int*)calloc((n + 1), sizeof(int));

    for (int i = 0; i <= n; i++) {
        tree[i] = (int*)malloc(n * sizeof(int));
    }

    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        tree[u][treeSize[u]++] = v;
    }

    
    struct Queue* q = createQueue();
    int* vis = (int*)calloc((n + 1), sizeof(int));

    
    enqueue(q, 1);

    
    while (!isEmpty(q)) {
        
        u = dequeue(q);
        printf("%d ", u);

        
        vis[u] = 1;

        
        for (int i = 0; i < treeSize[u]; i++) {
            v = tree[u][i];
            if (!vis[v]) {
                enqueue(q, v);
            }
        }
    }

    
    for (int i = 0; i <= n; i++) {
        free(tree[i]);
    }
    free(tree);
    free(treeSize);
    free(vis);
    free(q);

    return 0;
}