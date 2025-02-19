#include <stdio.h>
#include <limits.h>

#define WAREHOUSES 5
#define LOCATIONS 10
#define N (WAREHOUSES + LOCATIONS) 
#define INF 99999  

int findMinDistance(int distance[], int visited[]) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[N][N], int src) {
    int distance[N], visited[N];

    for (int i = 0; i < N; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[src] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = findMinDistance(distance, visited);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from warehouse %d:\n", src + 1);
    for (int i = WAREHOUSES; i < N; i++) {
        printf("To location %d: %d\n", i - WAREHOUSES + 1, distance[i]);
    }
    printf("\n");
}

int main() {
    int graph[N][N];

    printf("Enter distance matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < WAREHOUSES; i++) {
        dijkstra(graph, i);
    }

    return 0;
}

/* Logistics and Supply Chain Optimization:
Write a C program to optimize the logistics and supply chain of Flipkart's platform. Assume that the
platform has 5 warehouses and 10 delivery locations. Write a program to find the shortest path
between each warehouse and delivery location using Dijkstra's algorithm. */
