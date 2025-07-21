struct Edge {
    int u, v, w;
};
bool bellmanFord(int n, int start, const vector<Edge>& edges, vector<int>& dist) {
    const int INF = 1e9;
    dist.assign(n, INF), dist[start] = 0;
    for (int i = 1; i <= n; ++i) {
        bool changed = false;
        for (auto [u, v, w] : edges)
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w, changed = true;
                if (i == n) return false;
            }
        if (!changed) break;
    }
    return true;
}
