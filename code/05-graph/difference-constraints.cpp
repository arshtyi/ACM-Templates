bool differenceConstraints(int n, const vector<tuple<int, int, int>>& edges, vector<int>& dist) {
    vector<vector<pair<int, int>>> graph(n);
    for (auto [u, v, w] : edges) graph[u].push_back({v, w});
    dist.assign(n, 0);
    vector<int> cnt(n, 0), inq(n, 1);
    queue<int> q;
    for (int i = 0; i < n; ++i) q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop(), inq[u] = false;
        for (auto [v, w] : graph[u]) {
            if (dist[v] <= dist[u] + w) continue;
            dist[v] = dist[u] + w;
            if (++cnt[v] >= n) return false;
            if (!inq[v]) q.push(v), inq[v] = true;
        }
    }
    return true;
}
