#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200005;

vector<int> adj[MAX_N];
vector<int> dist(MAX_N, -1);

int bfs(int start, int n) {
    queue<int> q;
    dist[start] = 1;  

    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  
                dist[neighbor] = dist[node] + 1;  
                q.push(neighbor);

                
                if (neighbor == n) {
                    return dist[neighbor];
                }
            }
        }
    }

    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    
    int result = bfs(1, N);
    cout << result << endl;

    return 0;
}
