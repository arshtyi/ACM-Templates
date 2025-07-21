struct EulerTrail {
    struct Edge {
        int to, id;
    };
    int n, edgeCnt = 0;
    vector<vector<Edge>> graph;
    vector<int> deg, used, it, path;
    EulerTrail(int n = 0) { init(n); }
    void init(int n_) {
        n = n_, edgeCnt = 0;
        graph.assign(n, {}), deg.assign(n, 0);
    }
    void addEdge(int u, int v) {
        graph[u].push_back({v, edgeCnt});
        graph[v].push_back({u, edgeCnt});
        deg[u]++, deg[v]++, edgeCnt++;
    }
    void dfs(int u) {
        for (int& i = it[u]; i < (int)graph[u].size();) {
            Edge e = graph[u][i++];
            if (used[e.id]) continue;
            used[e.id] = true, dfs(e.to);
        }
        path.push_back(u);
    }
    int start(int fallback = 0) const {
        for (int i = 0; i < n; ++i)
            if (deg[i] & 1) return i;
        for (int i = 0; i < n; ++i)
            if (deg[i]) return i;
        return fallback;
    }
    vector<int> solve(int s) {
        int odd = 0;
        for (int i = 0; i < n; ++i) odd += deg[i] & 1;
        if (odd != 0 && odd != 2) return {};
        if (odd == 2 && !(deg[s] & 1)) s = start(s);
        if (odd == 0 && !deg[s]) s = start(s);
        used.assign(edgeCnt, 0), it.assign(n, 0), path.clear();
        dfs(s), reverse(path.begin(), path.end());
        if ((int)path.size() != edgeCnt + 1) return {};
        return path;
    }
};
