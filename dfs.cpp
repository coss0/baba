#include <iostream>
#include <vector>
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

    // Recursive function to perform Depth-First Search traversal
    void DFSUtil(int v, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    // Function to perform Depth-First Search traversal
    void DFS(int start) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Call the recursive helper function to print DFS traversal
        DFSUtil(start, visited);
    }
};

int main() {
    // Create a graph given in the example
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    cout << "Graph traversal using Depth-First Search (DFS): ";
    g.DFS(0); // Start DFS traversal from vertex 0

    return 0;
}
