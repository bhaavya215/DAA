#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void addEdge(vector<vector<pair<int, int> > >&graph, int from, int to, int weight) {
    graph[from].push_back(make_pair(to, weight));
    graph[to].push_back(make_pair(from, weight));
}

void dijkstra(int source, const vector<vector<pair<int, int> > >&graph, vector<int>&dist) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dist.assign(n, INT_MAX);
    dist[source] = 0;

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if(dist[u] == INT_MAX)
            break;
        visited[u] = true;

        for(int k = 0; k < graph[u].size(); k++) {
            int v = graph[u][k].first;
            int w = graph[u][k].second;

            if(dist[v] > dist[u] + w) 
                dist[v] = dist[u] + w;
        }
    } 
}

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    vector<vector<pair<int, int> > > graph(n);
    cout << "Enter edges (u v weight): " << endl;
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(graph, u, v, w);
    }

    int source, destination;
    cout << "enter source and destination: ";
    cin >> source >> destination;

    vector<int> dist;
    dijkstra(source, graph, dist);

    if(dist[destination] == INT_MAX)
        cout << "No path from " << source << " to " << destination << endl;
    else
        cout << "Shortest distance: " << dist[destination] << endl;

    return 0;
}