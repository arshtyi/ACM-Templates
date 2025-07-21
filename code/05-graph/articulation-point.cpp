struct ArticulationPoint {
    vector<int> dfn, low, cut;
    int timer = 0;
    void dfs(int u, int parent, const vector<vector<int>>& graph) {
        dfn[u] = low[u] = ++timer;
        int child = 0;
        for (int v : graph[u]) {
            if (!dfn[v]) {
                child++, dfs(v, u, graph), low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= dfn[u]) cut[u] = true;
            } else if (v != parent) low[u] = min(low[u], dfn[v]);
        }
        if (parent == -1 && child > 1) cut[u] = true;
    }
    vector<int> solve(const vector<vector<int>>& graph) {
        int n = graph.size();
        timer = 0;
        dfn.assign(n, 0), low.assign(n, 0), cut.assign(n, 0);
        for (int i = 0; i < n; ++i)
            if (!dfn[i]) dfs(i, -1, graph);
        vector<int> res;
        for (int i = 0; i < n; ++i)
            if (cut[i]) res.push_back(i);
        return res;
    }
};
