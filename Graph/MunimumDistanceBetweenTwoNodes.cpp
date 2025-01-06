#include <bits/stdc++.h>
using namespace std;

int findShortestPath(int N, int M, vector<pair<int, int>>& edges, int x, int y) {
    
    vector<vector<int>> adj(N + 1);  
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    
    vector<int> dist(N + 1, -1);  
    queue<int> q;
    q.push(x);
    dist[x] = 0;  

    
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);

                
                if (neighbor == y) {
                    return dist[neighbor];
                }
            }
        }
    }

    
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int x, y;
    cin >> x >> y;

    
    int result = findShortestPath(N, M, edges, x, y);
    cout << result << endl;

    return 0;
}
