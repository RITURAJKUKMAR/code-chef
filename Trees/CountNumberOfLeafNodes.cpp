#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[100001]; 
bool visited[100001];     
int leafCount = 0;
void dfs(int node, int parent) {
    bool isLeaf = true; 

    
    for (int child : tree[node]) {
        if (child != parent) { 
            isLeaf = false;    
            dfs(child, node);  
        }
    }
    if (isLeaf) {
        leafCount++;
    }
}
int main() {
    int n;
    cin >> n; 
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0, -1);
    cout << leafCount << endl;
    return 0;
}
