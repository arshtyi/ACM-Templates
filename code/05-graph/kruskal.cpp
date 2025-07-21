struct Edge {
    int u, v, w;
    bool operator<(const Edge& e) const { return w < e.w; }
};
int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int cost = 0, cnt = 0;
    for (auto [u, v, w] : edges) {
        if (!dsu.unite(u, v)) continue;
        cost += w, cnt++;
        if (cnt == n - 1) break;
    }
    return cnt == n - 1 ? cost : -1;
}
