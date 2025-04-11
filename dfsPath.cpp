/*given a graph, design an algorithm and implement it using a program to find if a path exists between 2 
given vertices or not.*/

#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int> > &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // undirected graph
}

bool dfs(int src, int dest, vector<vector<int> > &adj, vector<bool> &visited) {
    if (src == dest) 
        return true;

    visited[src] = true;

    for (int i = 0; i < adj[src].size(); i++) {
        int neighbor = adj[src][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, adj, visited))
                return true;
        }
    }
    return false;
}

// Function to check if a path exists using DFS
bool pathExist(int v, vector<vector<int> > &adj, int src, int dest) {
    vector<bool> visited(v, false);
    return dfs(src, dest, adj, visited);
}

int main() {
    int V, E; //no. of vertices & edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int> > adj(V);

    cout << "Enter edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int src, dest;
    cout << "Enter source and destination vertex: ";
    cin >> src >> dest;

    if (pathExist(V, adj, src, dest))
        cout << "Yes Path Exists." << endl;
    else
        cout << "No Such Path Exists." << endl;

    return 0;
}
