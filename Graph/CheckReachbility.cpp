#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &reachable) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        reachable.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    
    vector<vector<int>> adj(N + 1); 

    
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    
    vector<bool> visited(N + 1, false);
    vector<int> reachable;

    
    bfs(1, adj, visited, reachable);

    
    sort(reachable.begin(), reachable.end());

    
    for (int node : reachable) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
