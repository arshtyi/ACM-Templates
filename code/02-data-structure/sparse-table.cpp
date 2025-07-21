struct SparseTable {
    vector<int> lg;
    vector<vector<int>> st;
    int merge(int a, int b) const { return max(a, b); }
    void build(const vector<int>& a) {
        int n = a.size() - 1;
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
        st.assign(lg[n] + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) st[0][i] = a[i];
        for (int k = 1; k <= lg[n]; ++k)
            for (int i = 1; i + (1 << k) - 1 <= n; ++i) st[k][i] = merge(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
    int query(int l, int r) const {
        int k = lg[r - l + 1];
        return merge(st[k][l], st[k][r - (1 << k) + 1]);
    }
};
