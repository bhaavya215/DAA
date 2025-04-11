/*Given a directed graph, design an algorithm and implement it using a program to find whether a cycle 
exists in the graph or not.*/

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int v, vector<vector<int> > &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            if (dfs(u, adj, visited, recStack))
                return true;
        } else if (recStack[u]) {
            return true;
        }
    }
    
    recStack[v] = false;  // Backtrack
    return false;
}

bool isCyclic(vector<vector<int> > &adj, int V) {
    vector<bool> visited(V, false), recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
                return true;
        }
    }

    return false;
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
        adj[u].push_back(v);  // Directed edge from u to v
    }

    if (isCyclic(adj, V))
        cout << "Yes Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";

    return 0;
}
