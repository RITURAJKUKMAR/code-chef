#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        dist[u][v] = min(dist[u][v], w); 
        dist[v][u] = min(dist[v][u], w); 
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == INF) {
                cout << "-1 "; 
            } else {
                cout << dist[i][j] << " "; 
            }
        }
        cout << endl;
    }
    return 0;
}
