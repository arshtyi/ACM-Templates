struct LCA {
    int LOG;
    vector<int> dep;
    vector<vector<int>> up;
    void init(const vector<vector<int>>& tree, int root = 0) {
        int n = tree.size();
        LOG = __lg(max(1, n)) + 1;
        dep.assign(n, 0), up.assign(n, vector<int>(LOG));
        dfs(root, root, tree);
    }
    void dfs(int u, int p, const vector<vector<int>>& tree) {
        up[u][0] = p;
        for (int i = 1; i < LOG; ++i) up[u][i] = up[up[u][i - 1]][i - 1];
        for (int v : tree[u])
            if (v != p) dep[v] = dep[u] + 1, dfs(v, u, tree);
    }
    int query(int a, int b) const {
        if (dep[a] < dep[b]) swap(a, b);
        for (int i = LOG - 1; i >= 0; --i)
            if (dep[a] - (1 << i) >= dep[b]) a = up[a][i];
        if (a == b) return a;
        for (int i = LOG - 1; i >= 0; --i)
            if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
        return up[a][0];
    }
};
