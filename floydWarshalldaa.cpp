#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

// Function to perform Floyd-Warshall algorithm
void floydWarshall(vector<vector<int> >& graph, int V) {
    vector<vector<int> > dist = graph;

    // Intermediate node k
    for (int k = 0; k < V; k++) {
        // Source node i
        for (int i = 0; i < V; i++) {
            // Destination node j
            for (int j = 0; j < V; j++) {
                // If node k is on the shortest path from i to j, update the distance
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4; // Number of vertices
    vector<vector<int> > graph(V, vector<int>(V, INF)); // Initialize the graph with INF

    // Update the graph with edge weights
    graph[0][0] = 0;
    graph[1][1] = 0;
    graph[2][2] = 0;
    graph[3][3] = 0;
    graph[0][1] = 5;
    graph[0][3] = 10;
    graph[1][2] = 3;
    graph[2][3] = 1;

    floydWarshall(graph, V);

    return 0;
}

