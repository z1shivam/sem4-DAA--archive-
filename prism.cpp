#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Structure to represent a vertex in the graph
struct Vertex {
    int index, key;
};

// Comparator for priority queue
struct CompareKey {
    bool operator()(const Vertex& v1, const Vertex& v2) const {
        return v1.key > v2.key;
    }
};

// Function to find Minimum Spanning Tree using Prim's algorithm
void PrimMST(vector<vector<int> >& graph, int V) {
    // Priority queue to store vertices with their keys
    priority_queue<Vertex, vector<Vertex>, CompareKey> pq;

    // Vector to store parent of each vertex in MST
    vector<int> parent(V, -1);

    // Vector to track if a vertex is in MST
    vector<bool> inMST(V, false);

    // Vector to store keys of vertices
    vector<int> key(V, INF);

    // Start with vertex 0
    Vertex start_vertex = {0, 0};
    pq.push(start_vertex);
    key[0] = 0;

    // Find MST
    while (!pq.empty()) {
        int u = pq.top().index;
        pq.pop();

        inMST[u] = true;

        // Update key values and enqueue adjacent vertices of u
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Print MST edges and calculate total cost
    int totalCost = 0;
    cout << "Edges of Minimum Spanning Tree:\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Initialize adjacency matrix with 0
    vector<vector<int> > graph(V, vector<int>(V, 0));

    cout << "Enter source, destination, and weight for each edge:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w; // Undirected graph
    }

    PrimMST(graph, V);

    return 0;
}

