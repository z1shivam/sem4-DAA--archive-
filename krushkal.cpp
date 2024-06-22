#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparator function to sort edges by weight
bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Find operation of union-find algorithm
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation of union-find algorithm
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find Minimum Spanning Tree using Kruskal's algorithm
void KruskalMST(vector<Edge>& edges, int V) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compare);

    // Allocate memory for creating V subsets
    vector<Subset> subsets(V);

    // Initialize each subset as a single element set with its rank as 0
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    vector<Edge> result;
    int e = 0; // Index variable to iterate over edges
    int i = 0; // Index variable to iterate over result[]

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < edges.size()) {
        // Pick the smallest edge
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause cycle, include it in result
        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    // Print the constructed MST
    cout << "Edges of Minimum Spanning Tree:\n";
    for (i = 0; i < result.size(); i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Create a vector to store all edges
    vector<Edge> edges(E);

    cout << "Enter source, destination, and weight for each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    KruskalMST(edges, V);

    return 0;
}

