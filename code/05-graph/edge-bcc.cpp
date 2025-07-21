struct EdgeBCC {
    struct Edge {
        int to, id;
    };
    int n, edgeCnt = 0, timer = 0;
    vector<vector<Edge>> graph;
    vector<int> dfn, low, bridge, comp;
    EdgeBCC(int n = 0) { init(n); }
    void init(int n_) {
        n = n_, edgeCnt = 0;
        graph.assign(n, {});
    }
    void addEdge(int u, int v) {
        graph[u].push_back({v, edgeCnt});
        graph[v].push_back({u, edgeCnt++});
    }
    void tarjan(int u, int inEdge) {
        dfn[u] = low[u] = ++timer;
        for (auto e : graph[u]) {
            if (e.id == inEdge) continue;
            int v = e.to;
            if (!dfn[v]) {
                tarjan(v, e.id), low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridge[e.id] = true;
            } else low[u] = min(low[u], dfn[v]);
        }
    }
    void paint(int u, int c) {
        comp[u] = c;
        for (auto e : graph[u])
            if (!bridge[e.id] && comp[e.to] == -1) paint(e.to, c);
    }
    int solve() {
        timer = 0;
        dfn.assign(n, 0), low.assign(n, 0), bridge.assign(edgeCnt, 0), comp.assign(n, -1);
        for (int i = 0; i < n; ++i)
            if (!dfn[i]) tarjan(i, -1);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (comp[i] == -1) paint(i, cnt++);
        return cnt;
    }
};
