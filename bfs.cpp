#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Graph class representing an undirected graph
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    // Function to perform Breadth-First Search traversal
    void BFS(int start) {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> q;

        // Mark the current node as visited and enqueue it
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            // Dequeue a vertex from queue and print it
            int u = q.front();
            q.pop();
            cout << u << " ";

            // Get all adjacent vertices of the dequeued vertex u.
            // If an adjacent vertex has not been visited, then mark it
            // visited and enqueue it.
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    // Create a graph given in the example
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph traversal using Breadth-First Search (BFS): ";
    g.BFS(0); // Start BFS traversal from vertex 0

    return 0;
}
