struct SuffixArray {
    vector<int> sa, rk, height;
    void build(const string& s) {
        int n = s.size(), m = 256;
        sa.assign(n, 0), rk.assign(n, 0), height.assign(n, 0);
        if (!n) return;
        vector<int> x(n), y(n), c(max(n, m) + 1, 0);
        for (int i = 0; i < n; ++i) c[x[i] = (unsigned char)s[i]]++;
        for (int i = 1; i < m; ++i) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
        for (int k = 1, p = 0; p < n; k <<= 1, m = p) {
            p = 0;
            for (int i = n - k; i < n; ++i) y[p++] = i;
            for (int i = 0; i < n; ++i)
                if (sa[i] >= k) y[p++] = sa[i] - k;
            fill(c.begin(), c.begin() + m, 0);
            for (int i = 0; i < n; ++i) c[x[i]]++;
            for (int i = 1; i < m; ++i) c[i] += c[i - 1];
            for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
            swap(x, y), x[sa[0]] = 0, p = 1;
            for (int i = 1; i < n; ++i) {
                int a = sa[i - 1], b = sa[i];
                if (y[a] == y[b] && (a + k < n ? y[a + k] : -1) == (b + k < n ? y[b + k] : -1)) x[b] = p - 1;
                else x[b] = p++;
            }
        }
        for (int i = 0; i < n; ++i) rk[sa[i]] = i;
        for (int i = 0, k = 0; i < n; ++i) {
            if (!rk[i]) continue;
            if (k) --k;
            int j = sa[rk[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
            height[rk[i]] = k;
        }
    }
};
