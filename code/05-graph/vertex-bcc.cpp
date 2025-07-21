struct VertexBCC {
    vector<int> dfn, low, cut;
    vector<vector<int>> bcc;
    vector<pair<int, int>> stk;
    int timer = 0;
    void dfs(int u, int parent, const vector<vector<int>>& graph) {
        dfn[u] = low[u] = ++timer;
        int child = 0;
        for (int v : graph[u]) {
            if (!dfn[v]) {
                stk.push_back({u, v}), child++;
                dfs(v, u, graph), low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    if (parent != -1 || child > 1) cut[u] = true;
                    vector<int> cur;
                    while (true) {
                        auto e = stk.back();
                        stk.pop_back(), cur.push_back(e.first), cur.push_back(e.second);
                        if (e.first == u && e.second == v) break;
                    }
                    sort(cur.begin(), cur.end());
                    cur.erase(unique(cur.begin(), cur.end()), cur.end());
                    bcc.push_back(cur);
                }
            } else if (v != parent && dfn[v] < dfn[u]) stk.push_back({u, v}), low[u] = min(low[u], dfn[v]);
        }
    }
    void solve(const vector<vector<int>>& graph) {
        int n = graph.size();
        timer = 0, stk.clear(), bcc.clear();
        dfn.assign(n, 0), low.assign(n, 0), cut.assign(n, 0);
        for (int i = 0; i < n; ++i)
            if (!dfn[i]) {
                if (graph[i].empty()) bcc.push_back({i});
                else dfs(i, -1, graph);
            }
    }
};
