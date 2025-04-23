#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

struct Edge {
    int from, to, weight;
};

void bellmanFord(int V, int source, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(const Edge& edge : edges) {
            if(dist[edge.to] != INT_MAX && dist[edge.from] > dist[edge.to] + edge.weight) {
                dist[edge.from] = dist[edge.to] + edge.weight;
                parent[edge.from] = edge.to;
            }
        }
    }

    for(int i = 0; i < V; i++) {
        cout << "Path from " << i << " to " << source << ": ";
        if(dist[i] == INT_MAX) {
            cout << "No path | Distance: ∞" << endl;
        } else {
            stack<int> path;
            int curr = i;
            while(curr != -1) {
                path.push(curr);
                curr = parent[curr];
            }
            while(!path.empty()) {
                cout << path.top();
                path.pop();
                if(!path.empty()) cout << " -> ";
            }
            cout << " | Distance: " << dist[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w}); // undirected graph
    }

    int source;
    cout << "Enter Akshay's house node (source): ";
    cin >> source;

    bellmanFord(V, source, edges);

    return 0;
}