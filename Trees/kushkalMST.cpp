#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find_parent(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find_parent(parent[v]);
    }
    void merge_set(int a, int b)
    {
        a = find_parent(a);
        b = find_parent(b);
        if (size[b] > size[a])
        {
            swap(a, b);
        }
        parent[b] = a;
    }
    bool same_set(int a, int b)
    {
        if (find_parent(a) == find_parent(b))
        {
            return true;
        }
        return false;
    }
};

vector<vector<int>> edgeList; 

vector<pair<int, int>> MST; 

void kruskals(int n)
{ 
    

    sort(edgeList.begin(), edgeList.end());

    DSU dsu(n); 
    long long mst_weight = 0;
    vector<pair<int, int>> mst_edges; 

    
    for (auto &edge : edgeList)
    {
        int w = edge[0], u = edge[1], v = edge[2];

        
        if (!dsu.same_set(u, v))
        {
            
            dsu.merge_set(u, v);         
            mst_weight += w;             
            mst_edges.push_back({u, v}); 
        }
    }

    
    cout << mst_weight << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edgeList.push_back({w, a, b});
    }

    kruskals(n);

    return 0;
}
