// q4_dijkstra.cpp
#include <iostream>
using namespace std;

int findMin(int dist[], bool visited[], int n) {
    int minVal = 999999, idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < minVal) {
            minVal = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int **adj, int n, int src) {
    int dist[100];
    bool visited[100] = {false};

    for (int i = 0; i < n; i++)
        dist[i] = 999999;

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = findMin(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0 && !visited[v] &&
                dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Distance to " << i << ": " << dist[i] << "\n";
}

int main() {
    int n;
    cin >> n;

    int **adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    }

    int src;
    cin >> src;

    dijkstra(adj, n, src);

    return 0;
}
