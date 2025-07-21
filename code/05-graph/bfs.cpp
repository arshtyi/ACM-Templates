vector<int> bfs(int start, const vector<vector<int>>& graph) {
    queue<int> q;
    vector<int> dist(graph.size(), -1);
    q.push(start), dist[start] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
            if (dist[v] == -1) dist[v] = dist[u] + 1, q.push(v);
    }
    return dist;
}
