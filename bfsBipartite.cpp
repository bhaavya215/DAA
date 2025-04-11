/*Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite
or not.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int> > &adj, int V) {
    vector<int> color(V, -1);  // -1 means unvisited
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {  // If not colored, start BFS
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Assign opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;  
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int> > adj(V);

    cout << "Enter edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    if (isBipartite(adj, V))
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    return 0;
}