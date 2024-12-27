#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

// Comparator to sort edges by weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Disjoint Set Union (DSU) or Union-Find Class
class DSU {
private:
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the root of a node with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union two sets
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal's Algorithm
void kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges); // Sort edges by weight

    DSU dsu(n); // Create a DSU for 'n' vertices
    vector<Edge> mst; // To store the edges of the MST
    int mstWeight = 0;

    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree:\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total Weight of MST: " << mstWeight << "\n";
}

int main() {
    int n = 5; // Number of vertices
    vector<Edge> edges;

    // Adding edges (u, v, weight)
    edges.emplace_back(0, 1, 10);
    edges.emplace_back(0, 2, 6);
    edges.emplace_back(0, 3, 5);
    edges.emplace_back(1, 3, 15);
    edges.emplace_back(2, 3, 4);

    cout << "Graph Edges:\n";
    for (const auto& edge : edges) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    cout << "\nApplying Kruskal's Algorithm:\n";
    kruskalMST(n, edges);

    return 0;
}
