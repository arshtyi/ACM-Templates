vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& graph) {
    const int INF = 1e9;
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start), dist[start] = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : graph[u])
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w, pq.emplace(dist[v], v);
    }
    return dist;
}
