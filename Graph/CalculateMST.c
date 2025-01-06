#include <stdio.h>
#include <stdlib.h>

// Disjoint Set Union (DSU) structure
struct DSU
{
    int *parent;
    int *size;
};

// Function to initialize the DSU
void initialize_DSU(struct DSU *d, int n)
{
    d->parent = (int *)malloc((n + 1) * sizeof(int));
    d->size = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        d->parent[i] = i;
        d->size[i] = 1;
    }
}

// Function to find the parent with path compression
int find_parent(struct DSU *d, int v)
{
    if (d->parent[v] == v)
        return v;
    return d->parent[v] = find_parent(d, d->parent[v]);
}

// Function to merge two sets
void merge_set(struct DSU *d, int a, int b)
{
    a = find_parent(d, a);
    b = find_parent(d, b);
    if (d->size[b] > d->size[a])
    {
        int temp = a;
        a = b;
        b = temp;
    }
    d->parent[b] = a;
}

// Function to check if two elements are in the same set
int same_set(struct DSU *d, int a, int b)
{
    return find_parent(d, a) == find_parent(d, b);
}

// Edge structure
struct Edge
{
    int weight;
    int vertex1;
    int vertex2;
};

// Comparison function for qsort
int compare_edges(const void *a, const void *b)
{
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal's algorithm
void kruskals(struct Edge edgeList[], int n, int m)
{
    // Write your solution
    qsort(edgeList, m, sizeof(struct Edge), compare_edges);
    struct DSU dsu;
    initialize_DSU(&dsu, n);

    int mstWeight = 0;
    int edgesUsed = 0;
    printf("\nEdges in the MST:\n");

    for (int i = 0; i < m; i++) {
        int u = edgeList[i].vertex1;
        int v = edgeList[i].vertex2;
        assert(u >= 1 && u <= n && v >= 1 && v <= n);

        if (!same_set(&dsu, u, v)) {
            merge_set(&dsu, u, v);
            mstWeight += edgeList[i].weight;
            edgesUsed++;
            // printf("%d -- %d (weight: %d)\n", u, v, edgeList[i].weight);
        }

        if (edgesUsed == n - 1) {
            break;
        }
    }

    if (edgesUsed == n - 1) {
        printf("%d\n", mstWeight);
    } 

    free(dsu.parent);
    free(dsu.size);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    struct Edge *edgeList = (struct Edge *)malloc(m * sizeof(struct Edge));
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edgeList[i].vertex1, &edgeList[i].vertex2, &edgeList[i].weight);
    }
    kruskals(edgeList, n, m);
    free(edgeList);
    return 0;
}