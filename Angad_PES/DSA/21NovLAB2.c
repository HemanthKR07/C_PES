#include <stdio.h>
#include <stdbool.h>

bool isMeshTopology(int edges[][2], int m, int n);
bool isRingTopology(int edges[][2], int m, int n);

int main() {
    int n, m;
    
    // Read the number of vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);
    
    int edges[1000][2];  // Array to store edges
    
    // Read the edges (each edge is a pair of vertices)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }
    
    // Determine the topology
    if (isMeshTopology(edges, m, n)) {
        printf("The graph has a Mesh topology.\n");
    } else if (isRingTopology(edges, m, n)) {
        printf("The graph has a Ring topology.\n");
    } else {
        printf("The graph is incomplete.\n");
    }

    return 0;
}

bool isMeshTopology(int edges[][2], int m, int n) {
    if (m != n * (n - 1) / 2) {
        return false;
    }

    int degree[100] = {0};

    for (int i = 0; i < m; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] != n - 1) {
            return false;
        }
    }

    return true;
}

bool isRingTopology(int edges[][2], int m, int n) {
    if (m != n) {
        return false;
    }

    int degree[100] = {0};

    for (int i = 0; i < m; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 0; i < n; i++) {
        if (degree[i] != 2) {
            return false;
        }
    }

    return true;
}