struct SegTree {
    int n;
    vector<int> tree, lazy;
    SegTree(int n = 0) { init(n); }
    void init(int n_) {
        n = n_;
        tree.assign(n * 4 + 4, 0), lazy.assign(n * 4 + 4, 0);
    }
    void pushup(int x) { tree[x] = tree[x << 1] + tree[x << 1 | 1]; }
    void apply(int x, int l, int r, int v) { tree[x] += v * (r - l + 1), lazy[x] += v; }
    void pushdown(int x, int l, int r) {
        if (!lazy[x]) return;
        int mid = (l + r) >> 1;
        apply(x << 1, l, mid, lazy[x]), apply(x << 1 | 1, mid + 1, r, lazy[x]), lazy[x] = 0;
    }
    void build(int x, int l, int r, const vector<int>& a) {
        if (l == r) return tree[x] = a[l], void();
        int mid = (l + r) >> 1;
        build(x << 1, l, mid, a), build(x << 1 | 1, mid + 1, r, a), pushup(x);
    }
    void build(const vector<int>& a) { init((int)a.size() - 1), build(1, 1, n, a); }
    void add(int x, int l, int r, int ql, int qr, int v) {
        if (ql <= l && r <= qr) return apply(x, l, r, v);
        pushdown(x, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) add(x << 1, l, mid, ql, qr, v);
        if (qr > mid) add(x << 1 | 1, mid + 1, r, ql, qr, v);
        pushup(x);
    }
    int query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[x];
        pushdown(x, l, r);
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += query(x << 1, l, mid, ql, qr);
        if (qr > mid) res += query(x << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }
};
