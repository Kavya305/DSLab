// q1_bfs.cpp
#include <iostream>
using namespace std;

void bfs(int **adj, int n, int start) {
    bool visited[100] = {false};
    int queue[100], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        cout << u << " ";

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }
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

    int start;
    cin >> start;

    bfs(adj, n, start);

    return 0;
}
