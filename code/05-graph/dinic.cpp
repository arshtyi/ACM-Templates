struct Dinic {
    struct Edge {
        int to, rev, cap;
    };
    vector<vector<Edge>> graph;
    vector<int> level, it;
    Dinic(int n) : graph(n), level(n), it(n) {}
    void addEdge(int from, int to, int cap) {
        graph[from].push_back({to, (int)graph[to].size(), cap});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0});
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0, q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : graph[u])
                if (e.cap > 0 && level[e.to] < 0) level[e.to] = level[u] + 1, q.push(e.to);
        }
        return level[t] >= 0;
    }
    int dfs(int u, int t, int f) {
        if (u == t) return f;
        for (int& i = it[u]; i < (int)graph[u].size(); ++i) {
            Edge& e = graph[u][i];
            if (e.cap <= 0 || level[e.to] != level[u] + 1) continue;
            int ret = dfs(e.to, t, min(f, e.cap));
            if (ret) {
                e.cap -= ret, graph[e.to][e.rev].cap += ret;
                return ret;
            }
        }
        return 0;
    }
    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int f = dfs(s, t, INT_MAX)) flow += f;
        }
        return flow;
    }
};
