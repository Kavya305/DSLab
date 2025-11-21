// q3_mst.cpp
#include <iostream>
using namespace std;

// ---------- Disjoint Set (Union-Find) for Kruskal ----------
int parent[100], rnk[100];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }
}

int findSet(int x) {
    if (parent[x] != x)
        parent[x] = findSet(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rnk[a] < rnk[b]) parent[a] = b;
        else if (rnk[b] < rnk[a]) parent[b] = a;
        else {
            parent[b] = a;
            rnk[a]++;
        }
    }
}

// ---------- KRUSKAL (using edge list) ----------
struct Edge {
    int u, v, w;
};

void kruskal(Edge edges[], int n, int m) {
    // Simple bubble sort by weight
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    makeSet(n);
    cout << "Kruskal MST edges:\n";

    int count = 0;
    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findSet(u) != findSet(v)) {
            cout << u << " - " << v << "  (" << edges[i].w << ")\n";
            unionSet(u, v);
            count++;
        }
    }
}

// ---------- PRIM (Adjacency Matrix) ----------
void prim(int **adj, int n) {
    bool selected[100] = {false};
    int key[100], parentPrim[100];

    for (int i = 0; i < n; i++) {
        key[i] = 999999;
        parentPrim[i] = -1;
    }

    key[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++)
            if (!selected[j] && (u == -1 || key[j] < key[u]))
                u = j;

        selected[u] = true;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !selected[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
                parentPrim[v] = u;
            }
        }
    }

    cout << "\nPrim MST edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parentPrim[i] << " - " << i
             << " (" << adj[i][parentPrim[i]] << ")\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    Edge edges[100];

    int **adj = new int*[n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u][edges[i].v] = edges[i].w;
        adj[edges[i].v][edges[i].u] = edges[i].w;
    }

    kruskal(edges, n, m);
    prim(adj, n);

    return 0;
}
