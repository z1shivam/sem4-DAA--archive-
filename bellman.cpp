#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(vector<Edge>& edges, int V, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex   Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    vector<Edge> edges;
    edges.push_back({0, 1, -1});
    edges.push_back({0, 2, 4});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 2});
    edges.push_back({1, 4, 2});
    edges.push_back({3, 2, 5});
    edges.push_back({3, 1, 1});
    edges.push_back({4, 3, -3});
    int src = 0; // Source vertex

    bellmanFord(edges, V, src);

    return 0;
}

