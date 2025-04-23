#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

int minCost(int u, int v, int k, vector<vector<Edge>>& graph, vector<vector<vector<int>>>& dp) {
    if (k == 0 && u == v) 
        return 0;
    if (k == 0) 
        return INF;
    if (dp[u][v][k] != -1) 
        return dp[u][v][k];

    int ans = INF;
    for (int i = 0; i < graph[u].size(); ++i) {
        int next = graph[u][i].to;
        int weight = graph[u][i].weight;
    
        int subpath = minCost(next, v, k - 1, graph, dp);
        if (subpath != INF)
            ans = min(ans, weight + subpath);
    }    

    return dp[u][v][k] = ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    cout << "Enter edges (from to weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source, destination, K;
    cout << "Enter source, destination and number of edges (K): ";
    cin >> source >> destination >> K;

    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(K + 1, -1)));

    int result = minCost(source, destination, K, graph, dp);

    if (result == INF)
        cout << "No path from " << source << " to " << destination << " with exactly " << K << " edges.\n";
    else
        cout << "Shortest path weight with exactly " << K << " edges: " << result << endl;

    return 0;
}