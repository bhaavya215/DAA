//WEEK 14, Q2
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    for (int u : graph[v])
        if (!visited[u])
            DFS(graph, u, visited);
}

int findMotherVertex(vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    int candidate = 0;

    // First pass: find a candidate mother vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            candidate = i;
        }
    }

    // Second pass: check if candidate is a real mother vertex
    fill(visited.begin(), visited.end(), false);
    DFS(graph, candidate, visited);
    
    for (bool v : visited)
        if (!v) return -1; // No mother vertex

    return candidate;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> graph(V);
    cout << "Enter edges (from to):\n";
    for (int i = 0; i < E; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    int mother = findMotherVertex(graph, V);
    if (mother == -1)
        cout << "No mother vertex found.\n";
    else
        cout << "Mother vertex is: " << mother << endl;

    return 0;
}
