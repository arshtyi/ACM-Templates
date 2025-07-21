struct TwoSAT {
    int n, timer = 0, cnt = 0;
    vector<vector<int>> graph;
    vector<int> dfn, low, stk, ins, comp, answer;
    TwoSAT(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        graph.assign(n * 2, {});
    }
    int id(int x, bool val) const { return x * 2 + val; }
    void addImp(int x, bool xv, int y, bool yv) { graph[id(x, xv)].push_back(id(y, yv)); }
    void addOr(int x, bool xv, int y, bool yv) {
        addImp(x, !xv, y, yv);
        addImp(y, !yv, x, xv);
    }
    void addUnit(int x, bool xv) { addImp(x, !xv, x, xv); }
    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u), ins[u] = true;
        for (int v : graph[u]) {
            if (!dfn[v]) dfs(v), low[u] = min(low[u], low[v]);
            else if (ins[v]) low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            while (true) {
                int v = stk.back();
                stk.pop_back(), ins[v] = false, comp[v] = cnt;
                if (v == u) break;
            }
            cnt++;
        }
    }
    bool solve() {
        int m = n * 2;
        timer = cnt = 0, stk.clear();
        dfn.assign(m, 0), low.assign(m, 0), ins.assign(m, 0), comp.assign(m, -1);
        for (int i = 0; i < m; ++i)
            if (!dfn[i]) dfs(i);
        answer.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (comp[i * 2] == comp[i * 2 + 1]) return false;
            answer[i] = comp[i * 2] > comp[i * 2 + 1];
        }
        return true;
    }
};
