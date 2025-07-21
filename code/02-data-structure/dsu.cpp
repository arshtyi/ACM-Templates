struct DSU {
    vector<int> fa, sz;
    DSU(int n = 0) { init(n); }
    void init(int n) {
        fa.resize(n), sz.assign(n, 1);
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        return fa[b] = a, sz[a] += sz[b], true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
};
