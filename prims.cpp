#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define an edge structure to represent edges in the graph
struct Edge {
    int to;
    int weight;
};

// Define a comparison operator for the priority queue
struct CompareEdges {
    bool operator()(const Edge& e1, const Edge& e2) const {
        return e1.weight > e2.weight;
    }
};

// Graph class representing an undirected graph
class Graph {
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Assuming undirected graph
    }

    // Function to find minimum spanning tree using Prim's algorithm
    void primMST() {
        // Priority queue to store edges
        priority_queue<Edge, vector<Edge>, CompareEdges> pq;

        // Vector to store key values used to pick minimum weight edge
        vector<int> key(V, INT_MAX);

        // Vector to store whether a vertex is included in MST or not
        vector<bool> inMST(V, false);

        // Start with vertex 0
        int src = 0;
        pq.push({src, 0});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().to;
            pq.pop();

            // Include the picked vertex in MST
            inMST[u] = true;

            // Traverse all adjacent vertices of u
            for (const Edge& e : adj[u]) {
                int v = e.to;
                int weight = e.weight;

                // If v is not in MST and weight of (u,v) is smaller than current key of v
                if (!inMST[v] && weight < key[v]) {
                    // Update key value and push it to priority queue
                    key[v] = weight;
                    pq.push({v, key[v]});
                }
            }
        }

        // Print the edges of the minimum spanning tree
        cout << "Edges of the Minimum Spanning Tree (Prim's Algorithm):" << endl;
        for (int i = 1; i < V; i++) {
            cout << i << " - " << key[i] << endl;
        }
    }
};

int main() {
    // Create a graph given in the example
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Find and print the minimum spanning tree
    g.primMST();

    return 0;
}
