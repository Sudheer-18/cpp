#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    pq.push({0, src}); 

    while (!pq.empty()) {
        int d = pq.top()[0];
        int u = pq.top()[1];
        pq.pop();
        if (d > dist[u]) continue; 
        for (auto edge : edges) {
            int v = edge[1];
            int weight = edge[2];
            if (edge[0] == u) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    return dist;
}

int main() {
    int V, E, src;
    cin >> V >> E >> src; 

    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    vector<int> result = dijkstra(V, edges, src);

    for(int x: result) {
        cout << x << " ";
    }

    return 0;
}
