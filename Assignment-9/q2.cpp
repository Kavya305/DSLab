// q2_dfs.cpp
#include <iostream>
using namespace std;

bool visited[100];

void dfs(int **adj, int n, int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !visited[v])
            dfs(adj, n, v);
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

    for (int i = 0; i < n; i++) visited[i] = false;

    int start;
    cin >> start;

    dfs(adj, n, start);

    return 0;
}
