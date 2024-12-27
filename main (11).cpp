#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& inMST, int n) {
    int minValue = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the MST
void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int n) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

// Function to implement Prim's Algorithm
void primMST(const vector<vector<int>>& graph, int n) {
    vector<int> key(n, INT_MAX);    // Minimum weight edge to include a vertex in the MST
    vector<int> parent(n, -1);     // To store the MST
    vector<bool> inMST(n, false);  // To track vertices included in the MST

    // Start with the first vertex
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex not in MST
        int u = minKey(key, inMST, n);
        inMST[u] = true;

        // Update key and parent of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    printMST(parent, graph, n);
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int n = graph.size();
    cout << "Minimum Spanning Tree using Prim's Algorithm:\n";
    primMST(graph, n);

    return 0;
}
