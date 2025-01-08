#include <stdio.h>

#include <stdlib.h>

#include <limits.h>

#include <stdbool.h>

#define INF LLONG_MAX

typedef long long ll;

typedef struct
{

    ll first, second;

} pii;

typedef struct
{

    ll u, v, w;

} edge;



void init(int n);

int find(int u);

void unionSets(int u, int v);

int compareEdges(const void *a, const void *b);

void push(pii *pq, int *size, pii node);

pii pop(pii *pq, int *size);

void heapifyUp(pii *pq, int idx);

void heapifyDown(pii *pq, int size, int idx);



int rnk[20005];

pii graph[20005][100]; 

int graph_size[20005];

ll dist[20005];

int edgeChosen[20005];

edge edgeList[100005]; 

int parent[20005];



void init(int n)
{

    for (int i = 0; i < n; i++)
    {

        parent[i] = i;

        rnk[i] = 0;
    }
}



int find(int u)
{

    if (u != parent[u])
    {

        parent[u] = find(parent[u]);
    }

    return parent[u];
}



void unionSets(int u, int v)
{

    int rootU = find(u);

    int rootV = find(v);

    if (rootU != rootV)
    {

        if (rnk[rootU] > rnk[rootV])
        {

            parent[rootV] = rootU;
        }
        else if (rnk[rootU] < rnk[rootV])
        {

            parent[rootU] = rootV;
        }
        else
        {

            parent[rootV] = rootU;

            rnk[rootU]++;
        }
    }
}
int compareEdges(const void *a, const void *b)
{
    edge *e1 = (edge *)a;
    edge *e2 = (edge *)b;
    return (e1->w > e2->w) - (e1->w < e2->w);
}
void push(pii *pq, int *size, pii node)
{
    pq[(*size)++] = node;
    heapifyUp(pq, *size - 1);
}
pii pop(pii *pq, int *size)
{
    pii top = pq[0];
    pq[0] = pq[--(*size)];
    heapifyDown(pq, *size, 0);
    return top;
}
void heapifyUp(pii *pq, int idx)
{
    while (idx > 0)
    {
        int parentIdx = (idx - 1) / 2;
        if (pq[idx].first >= pq[parentIdx].first)
            break;
        pii temp = pq[idx];
        pq[idx] = pq[parentIdx];
        pq[parentIdx] = temp;
        idx = parentIdx;
    }
}
void heapifyDown(pii *pq, int size, int idx)
{
    while (2 * idx + 1 < size)
    {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int smallest = idx;
        if (leftChild < size && pq[leftChild].first < pq[smallest].first)
            smallest = leftChild;
        if (rightChild < size && pq[rightChild].first < pq[smallest].first)
            smallest = rightChild;
        if (smallest == idx)
            break;
        pii temp = pq[idx];
        pq[idx] = pq[smallest];
        pq[smallest] = temp;
        idx = smallest;
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            graph_size[i] = 0;
            dist[i] = INF;
            edgeChosen[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u][graph_size[u]].first = v;
            graph[u][graph_size[u]].second = w;
            graph_size[u]++;
            graph[v][graph_size[v]].first = u;
            graph[v][graph_size[v]].second = w;
            graph_size[v]++;
            edgeList[i] = (edge){u, v, w};
        }
        qsort(edgeList, m, sizeof(edge), compareEdges);
        ll mst = 0;
        int cnt = 0;
        init(n);
        for (int i = 0; i < m; i++)
        {
            int u = edgeList[i].u;
            int v = edgeList[i].v;
            if (find(u) != find(v))
            {
                unionSets(u, v);
                mst += edgeList[i].w;
                cnt++;
            }
        }
        if (cnt != n - 1)
        {
            printf("NO\n");
            continue;
        }
        pii pq[20005];
        int pq_size = 0;
        push(pq, &pq_size, (pii){0, 0});
        dist[0] = 0;
        while (pq_size > 0)
        {
            pii node = pop(pq, &pq_size);
            int u = node.second;
            ll d = node.first;
            if (dist[u] < d)
                continue;
            for (int i = 0; i < graph_size[u]; i++)
            {
                int v = graph[u][i].first;
                ll w = graph[u][i].second;
                if (dist[v] > w + d)
                {
                    dist[v] = w + d;
                    push(pq, &pq_size, (pii){w + d, v});
                    edgeChosen[v] = w;
                }
                else if (dist[v] == w + d && w < edgeChosen[v])
                    edgeChosen[v] = w;
            }
        }
        ll mdt = 0;
        for (int i = 0; i < n; i++)
            mdt += edgeChosen[i];
        if (mdt == mst)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
