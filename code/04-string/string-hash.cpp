struct StringHash {
    static const int mod = 1000000007, base = 911382323;
    vector<int> h, p;
    void build(const string& s) {
        int n = s.size();
        h.assign(n + 1, 0), p.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            h[i] = (1LL * h[i - 1] * base + s[i - 1]) % mod;
            p[i] = 1LL * p[i - 1] * base % mod;
        }
    }
    int get(int l, int r) const {
        return (h[r] - 1LL * h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};
