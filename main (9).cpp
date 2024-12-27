#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void bfs(int startNode, const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of nodes
    vector<bool> visited(n, false); // Keep track of visited nodes
    queue<int> q; // Queue for BFS

    // Start BFS from the startNode
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        cout << currentNode << " ";

        // Visit all neighbors of the current node
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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
    cout << "Starting BFS from node " << startNode << ":\n";
    bfs(startNode, graph);

    return 0;
}
