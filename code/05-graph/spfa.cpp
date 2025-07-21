bool spfa(int start, const vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
    const int INF = 1e9;
    int n = graph.size();
    queue<int> q;
    vector<int> inq(n), cnt(n);
    dist.assign(n, INF);
    q.push(start), inq[start] = true, dist[start] = 0, cnt[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop(), inq[u] = false;
        for (auto [v, w] : graph[u])
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!inq[v]) {
                    q.push(v), inq[v] = true;
                    if (++cnt[v] >= n) return false;
                }
            }
    }
    return true;
}
