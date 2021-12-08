#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5

int min_distance(int dist[], int set[]) {
    int min_idx;
    int min = INT_MAX;
    for(int i = 0; i < V; i++) {
        if(set[i] == 0 && min >= dist[i]) {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void print_distance(int dist[], int src) {
    char c = 'A';
    printf("From Source: %c\n", c + src);
    for(int i = 0; i < V; i++) {
        printf("To %c requires: %d cost\n", c, dist[i]);
        c += 1;
    }
}

void dijkstra(int graph[][V + 5], int src) {
    int dist[V + 5];
    int set[V]; // shortest tree path (STP)

    // initialize
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        set[i] = 0;
    }

    // starts from src
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {
        int u = min_distance(dist, set);// get the shortest distance.
        set[u] = 1;
        for(int j = 0; j < V; j++) {
            // Rules:
            // 1. haven't available in the set
            // 2. reachable from u to neighbour
            // 3. new distance < old distance
            if(set[j] == 0 && graph[u][j] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][j] <= dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    // output
    print_distance(dist, src);
}

int main() {
    int graph[V + 5][V + 5] = {
        {0, 3, 1, 0, 0},
        {3, 0, 7, 5, 1},
        {1, 7, 0, 2, 0},
        {0, 5, 2, 0, 7},
        {0, 1, 0, 7, 0}
    };
    // int graph[V + 5][V + 5] = {
    //     {-1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1},
    //     {-1, -1, -1, -1, -1}
    // };
    dijkstra(graph, 1);
    return 0;
}