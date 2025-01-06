#include <bits/stdc++.h>
using namespace std;

const int maxx = 100005;
vector<int> tree[maxx];
bool visited[maxx];
void dfs(int node) {
    visited[node] = true; 
    cout << node << " ";  
    
    for (auto i: tree[node]) {
        if (!visited[i]) {  
            dfs(i);
        }
    }
}
int main() {
    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; i++) { 
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u); 
    }
    dfs(1);
    
    return 0;
}
