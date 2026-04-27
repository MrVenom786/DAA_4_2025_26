#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            return {-1};
        }
    }
    
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) dist[i] = 1e8;
    }
    
    return dist;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
    int src = 0;
    
    vector<int> result = bellmanFord(V, edges, src);
    for (int d : result) cout << d << " ";
    cout << endl;
    return 0;
}