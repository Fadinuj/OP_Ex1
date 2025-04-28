#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int, int>> adj[], int V, int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u]) {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    if (V <= 0) {
        cerr << "Number of vertices must be positive.\n";
        return 1;
    }

    vector<iPair> adj[V];

    cout << "Enter number of edges: ";
    cin >> E;
    if (E < 0) {
        cerr << "Number of edges cannot be negative.\n";
        return 1;
    }

    cout << "Enter edges in the format: u v weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        if (u < 0 || u >= V || v < 0 || v >= V) {
            cerr << "Invalid vertex number.\n";
            return 1;
        }
        if (wt < 0) {
            cerr << "Edge weights must be non-negative.\n";
            return 1;
        }
        addEdge(adj, u, v, wt);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    if (src < 0 || src >= V) {
        cerr << "Invalid source vertex.\n";
        return 1;
    }

    shortestPath(adj, V, src);

    return 0;
}
