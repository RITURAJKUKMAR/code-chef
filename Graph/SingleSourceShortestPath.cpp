#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const long long INF = 1e18;

long long d[N];
vector<pair<int,int>> adj[N];
bool vis[N];


void dijkstra(int source, int n) {
    
    
    fill(d, d + n + 1, INF);
    
    d[source] = 0;

    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, source}); 

    while (!pq.empty()) {
        
        long long dist_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        if (dist_u > d[u]) continue;

        
        for (auto edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;

            
            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({d[v], v}); 
            }
        }
}


         
}

int main() {
    int n, m; 
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(1, n);

    
    for(int i = 1; i <= n; i++) {
        if(d[i] == INF) cout << "-1 ";
        else cout << d[i] << " ";
    }

    return 0;
}