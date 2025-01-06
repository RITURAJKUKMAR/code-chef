#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
const int MAX_N = 20005;  
const int MAX_K = 1005;   

vector<pair<int, long long>> adj[MAX_N];   
long long dist[MAX_N];                      

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, S;
    cin >> N >> K >> S;
    S--; 

    vector<int> alliance(N);  
    for (int i = 0; i < N; i++) {
        cin >> alliance[i];
        alliance[i]--;  
    }

    vector<vector<int>> C(N, vector<int>(K));  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cin >> C[i][j];
        }
    }

    
    fill(dist, dist + N, INF);  
    dist[S] = 0;  

    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, S});  

    
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        if (d > dist[u]) continue;

        
        for (int v = 0; v < N; v++) {
            if (v != u && alliance[v] == alliance[u]) {  
                int travel_cost = C[u][alliance[v]];
                if (travel_cost != -1 && dist[u] + travel_cost < dist[v]) {
                    dist[v] = dist[u] + travel_cost;
                    pq.push({dist[v], v});
                }
            }
        }

        
        for (int j = 0; j < K; j++) {
            if (alliance[u] != j) {  
                int travel_cost = C[u][j];
                if (travel_cost != -1) {  
                    for (int v = 0; v < N; v++) {
                        if (alliance[v] == j && dist[u] + travel_cost < dist[v]) {
                            dist[v] = dist[u] + travel_cost;
                            pq.push({dist[v], v});
                        }
                    }
                }
            }
        }
    }

    
    for (int i = 0; i < N; i++) {
        if (dist[i] == INF) {
            cout << -1 << " ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
// not final