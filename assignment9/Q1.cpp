#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> adj;
    vector<Edge> edges;

    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    // Breadth First Search (BFS)
    vector<int> BFS(int start) {
        vector<int> vis(n, 0), order;
        queue<int> q;
        vis[start] = 1;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (auto &p : adj[u]) {
                int v = p.first;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return order;
    }

    // Depth First Search (DFS)
    void dfsUtil(int u, vector<int> &vis, vector<int> &order) {
        vis[u] = 1;
        order.push_back(u);
        for (auto &p : adj[u]) {
            int v = p.first;
            if (!vis[v]) dfsUtil(v, vis, order);
        }
    }

    vector<int> DFS(int start) {
        vector<int> vis(n, 0), order;
        dfsUtil(start, vis, order);
        return order;
    }

    // Minimum Spanning Tree (Kruskal)
    struct DSU {
        vector<int> parent, r;
        DSU(int n) {
            parent.resize(n);
            r.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a, b);
            parent[b] = a;
            if (r[a] == r[b]) r[a]++;
            return true;
        }
    };

    vector<Edge> kruskalMST() {
        vector<Edge> mst;
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
        DSU dsu(n);
        for (auto &e : edges) {
            if (dsu.unite(e.u, e.v)) mst.push_back(e);
        }
        return mst;
    }

    // Minimum Spanning Tree (Prim)
    vector<Edge> primMST(int start = 0) {
        vector<int> key(n, INT_MAX), parent(n, -1);
        vector<bool> inMST(n, false);
        key[start] = 0;
        for (int i = 0; i < n - 1; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && (u == -1 || key[j] < key[u])) u = j;
            }
            inMST[u] = true;
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        vector<Edge> mst;
        for (int v = 1; v < n; v++) {
            if (parent[v] != -1) mst.push_back({parent[v], v, key[v]});
        }
        return mst;
    }

    // Dijkstra's Shortest Path Algorithm
    vector<int> dijkstra(int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);

    cout << "BFS: ";
    for (int x : g.BFS(0)) cout << x << " ";
    cout << endl;

    cout << "DFS: ";
    for (int x : g.DFS(0)) cout << x << " ";
    cout << endl;

    cout << "\nKruskal MST:\n";
    for (auto &e : g.kruskalMST())
        cout << e.u << " - " << e.v << " : " << e.w << endl;

    cout << "\nPrim MST:\n";
    for (auto &e : g.primMST())
        cout << e.u << " - " << e.v << " : " << e.w << endl;

    cout << "\nDijkstra:\n";
    vector<int> d = g.dijkstra(0);
    for (int i = 0; i < d.size(); i++)
        cout << "0 -> " << i << " = " << d[i] << endl;

    return 0;
}
