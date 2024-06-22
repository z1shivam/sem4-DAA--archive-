#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent each edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int id;
    long long distance; // Change int to long long
};

// Function to implement Dijkstra's algorithm
void dijkstra(struct Edge** graph, int n, int source) {
    // Initialize distances to all vertices as infinite
    long long *distance = (long long *)malloc(n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        distance[i] = LLONG_MAX;
    }

    // Priority queue to store vertices with their distances from the source
    struct Vertex *pq = (struct Vertex *)malloc(n * sizeof(struct Vertex));
    int pq_size = 0;

    // Set distance of source vertex to itself as 0 and push it to the priority queue
    distance[source] = 0;
    pq[pq_size++] = (struct Vertex){source, 0};

    // Loop until priority queue is empty
    while (pq_size > 0) {
        // Extract the vertex with the smallest distance from the priority queue
        int min_index = 0;
        for (int i = 1; i < pq_size; i++) {
            if (pq[i].distance < pq[min_index].distance) {
                min_index = i;
            }
        }
        struct Vertex u = pq[min_index];
        pq[min_index] = pq[--pq_size];

        // Iterate through all adjacent vertices of u
        for (int i = 0; i < n; i++) {
            if (graph[u.id][i].weight > 0) {
                // Relaxation step: update distance if shorter path found
                if (distance[i] > u.distance + graph[u.id][i].weight) {
                    distance[i] = u.distance + graph[u.id][i].weight;
                    pq[pq_size++] = (struct Vertex){i, distance[i]};
                }
            }
        }
    }

    // Print the shortest distances from the source to all vertices
    printf("Shortest distances from source vertex %d:\n", source);
    for (int i = 0; i < n; ++i) {
        printf("Vertex %d: %lld\n", i, distance[i]);
    }

    free(distance);
    free(pq);
}

int main() {
    int n, m; // Number of vertices and edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Create adjacency list representation of the graph
    struct Edge** graph = (struct Edge**)malloc(n * sizeof(struct Edge*));
    for (int i = 0; i < n; i++) {
        graph[i] = (struct Edge*)malloc(n * sizeof(struct Edge));
    }

    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = (struct Edge){v, w};
        graph[v][u] = (struct Edge){u, w}; // For undirected graph
    }

    int source; // Source vertex for Dijkstra's algorithm
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Call Dijkstra's algorithm
    dijkstra(graph, n, source);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

