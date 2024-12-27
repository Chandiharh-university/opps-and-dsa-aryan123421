#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS
void dfsUtil(int currentNode, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[currentNode] = true;
    cout << currentNode << " "; // Process the current node

    // Recur for all neighbors of the current node
    for (int neighbor : graph[currentNode]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, graph, visited);
        }
    }
}

void dfs(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of nodes
    vector<bool> visited(n, false); // Keep track of visited nodes

    cout << "DFS Traversal: ";
    dfsUtil(startNode, graph, visited);
    cout << endl;
}

int main() {
    // Example graph as an adjacency list
    int n = 6; // Number of nodes
    vector<vector<int>> graph(n);

    // Adding edges
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int startNode = 0;
    cout << "Starting DFS from node " << startNode << ":\n";
    dfs(startNode, graph);

    return 0;
}
