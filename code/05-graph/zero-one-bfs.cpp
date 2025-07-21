vector<int> zeroOneBfs(int start, const vector<vector<pair<int, int>>>& graph) {
    const int INF = 1e9;
    deque<int> q;
    vector<int> dist(graph.size(), INF);
    q.push_back(start), dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        for (auto [v, w] : graph[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) q.push_front(v);
                else q.push_back(v);
            }
    }
    return dist;
}
