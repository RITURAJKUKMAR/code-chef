#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight; 
    }
};


class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false; 
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    
    sort(edges.begin(), edges.end());

    
    DSU dsu(n);

    long long mstWeight = 0;
    for (const auto& edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            mstWeight += edge.weight; 
        }
    }

    cout << mstWeight << endl;

    return 0;
}
