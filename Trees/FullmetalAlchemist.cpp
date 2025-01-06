#include <bits/stdc++.h>
using namespace std;
int calculate_cost(const string &row1, const string &row2) {
    int max_cost = 0;
    for (int i = 0; i < row1.size(); ++i) {
        max_cost = max(max_cost, abs(row1[i] - row2[i]));
    }
    return max_cost;
}
bool can_mark_with_max_cost(const vector<string> &grid, int n, int max_cost) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dist[i][j] = dist[j][i] = calculate_cost(grid[i], grid[j]);
        }
    }
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[u][v] <= max_cost) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    int low = 0, high = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            high = max(high, calculate_cost(grid[i], grid[j]));

    int answer = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (can_mark_with_max_cost(grid, n, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}
