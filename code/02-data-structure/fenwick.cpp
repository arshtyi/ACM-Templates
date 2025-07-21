struct Fenwick {
    int n;
    vector<int> tree;
    Fenwick(int n = 0) { init(n); }
    void init(int n_) { n = n_, tree.assign(n + 1, 0); }
    void add(int x, int val) {
        for (; x <= n; x += x & -x) tree[x] += val;
    }
    int sum(int x) const {
        int res = 0;
        for (; x > 0; x -= x & -x) res += tree[x];
        return res;
    }
    int query(int l, int r) const { return sum(r) - sum(l - 1); }
    int kth(int k) const {
        int x = 0;
        for (int i = 1 << __lg(n); i; i >>= 1)
            if (x + i <= n && tree[x + i] < k) k -= tree[x + i], x += i;
        return x + 1;
    }
};
