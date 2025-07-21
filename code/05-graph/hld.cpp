struct HLD {
    int n, timer = 0;
    vector<vector<int>> graph;
    vector<int> parent, depth, heavy, size, top, dfn, rev;
    HLD(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        graph.assign(n, {});
        parent.assign(n, -1), depth.assign(n, 0), heavy.assign(n, -1), size.assign(n, 0);
        top.assign(n, 0), dfn.assign(n, 0), rev.assign(n + 1, 0);
    }
    void addEdge(int u, int v) {
        graph[u].push_back(v), graph[v].push_back(u);
    }
    void dfs1(int u, int p) {
        parent[u] = p, size[u] = 1, heavy[u] = -1;
        for (int v : graph[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1, dfs1(v, u), size[u] += size[v];
            if (heavy[u] == -1 || size[v] > size[heavy[u]]) heavy[u] = v;
        }
    }
    void dfs2(int u, int tp) {
        top[u] = tp, dfn[u] = ++timer, rev[timer] = u;
        if (heavy[u] != -1) dfs2(heavy[u], tp);
        for (int v : graph[u])
            if (v != parent[u] && v != heavy[u]) dfs2(v, v);
    }
    void build(int root = 0) {
        timer = 0, depth[root] = 0;
        dfs1(root, -1), dfs2(root, root);
    }
    int lca(int u, int v) const {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            u = parent[top[u]];
        }
        return depth[u] < depth[v] ? u : v;
    }
    template <class F>
    void path(int u, int v, F f) const {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            f(dfn[top[u]], dfn[u]), u = parent[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        f(dfn[u], dfn[v]);
    }
    pair<int, int> subtree(int u) const { return {dfn[u], dfn[u] + size[u] - 1}; }
};
