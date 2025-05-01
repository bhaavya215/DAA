#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) const {
        return weight > other.weight; // For Maximum Spanning Tree
    }
};

int find(int u, vector<int> &parent) {
    if (u != parent[u])
        parent[u] = find(parent[u], parent); // Path compression
    return parent[u];
}

bool unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu == pv) return false;

    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pu] > rank[pv])
        parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
    return true;
}

int maximumSpanningTree(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end());
    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; ++i) parent[i] = i;

    int maxWeight = 0;
    for (Edge &e : edges) {
        if (unionSet(e.u, e.v, parent, rank)) {
            maxWeight += e.weight;
        }
    }

    return maxWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<Edge> edges;
    cout << "Enter the adjacency matrix (" << V << " x " << V << "):\n";

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int w;
            cin >> w;
            if (w != 0 && i < j) {
                edges.push_back({i, j, w});
            }
        }
    }

    int maxWeight = maximumSpanningTree(edges, V);
    cout << "Maximum Spanning Weight: " << maxWeight << '\n';

    return 0;
}