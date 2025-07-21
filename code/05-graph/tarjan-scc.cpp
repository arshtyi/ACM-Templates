struct TarjanSCC {
    vector<int> dfn, low, stk, ins, belong;
    vector<vector<int>> scc;
    int timer = 0;
    void dfs(int u, const vector<vector<int>>& graph) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u), ins[u] = true;
        for (int v : graph[u]) {
            if (!dfn[v]) dfs(v, graph), low[u] = min(low[u], low[v]);
            else if (ins[v]) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            scc.push_back({});
            while (true) {
                int v = stk.back();
                stk.pop_back(), ins[v] = false;
                belong[v] = scc.size() - 1, scc.back().push_back(v);
                if (v == u) break;
            }
        }
    }
    void solve(const vector<vector<int>>& graph) {
        int n = graph.size();
        timer = 0, stk.clear(), scc.clear();
        dfn.assign(n, 0), low.assign(n, 0), ins.assign(n, 0), belong.assign(n, -1);
        for (int i = 0; i < n; ++i)
            if (!dfn[i]) dfs(i, graph);
    }
};
